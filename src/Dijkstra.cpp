//
// Created by g on 10/19/17.
//

#include "../include/Dijkstra.h"
#include "../include/MinimumHeap.h"
#include <limits.h>

void Dijkstra::generate(std::shared_ptr<Graph> graph, int src) {

    int V = graph->numOfVertices;// Get the number of vertices in graph
    int dist[V];      // dist values used to pick minimum weight edge in cut

    // parent array to store shortest path tree
    std::vector<int> parent(V);

    // minHeap represents set E
    std::shared_ptr<MinimumHeap> minHeap = std::make_shared<MinimumHeap>(V);

    // Initialize min heap with all vertices. dist value of all vertices
    for (int v = 0; v < V; ++v) {
        parent[0] = -1;
        dist[v] = INT_MAX;
        HeapNode *newHeapNode = new HeapNode(v, dist[v]);
        minHeap->array[v] = newHeapNode;
        minHeap->pos[v] = v;
    }

    // Make dist value of src vertex as 0 so that it is extracted first
   HeapNode *newHeapNode2 = new HeapNode(src, dist[src]);
    minHeap->array[src] = newHeapNode2;
    minHeap->pos[src] = src;
    dist[src] = 0;
    minHeap->decreaseKey(src, dist[src]);

    // Initially size of min heap is equal to V
    minHeap->size = V;

    // In the followin loop, min heap contains all nodes
    // whose shortest distance is not yet finalized.
    while (!minHeap->isEmpty()) {
        // Extract the vertex with minimum distance value
        HeapNode *minHeapNode = minHeap->extractMin();
        int u = minHeapNode->v; // Store the extracted vertex number

        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        std::shared_ptr<Node> pCrawl = graph->arrayOfLists[u]->head;
        while (pCrawl != nullptr) {
            int v = pCrawl->destination;

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (minHeap->isInMinHeap(v) && dist[u] != INT_MAX &&
                pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                parent[v] = u;
                // update distance value in min heap also
                minHeap->decreaseKey(v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    // print the calculated shortest distances
    minHeap->printArray(dist, V, parent);
}
