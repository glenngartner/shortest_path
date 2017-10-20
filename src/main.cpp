// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph

#include <iostream>
#include <memory>
#include "../include/Graph.h"


int main()
{

    std::shared_ptr<Graph> graph = std::make_shared<Graph>(5);
    graph->addEdge(graph, 0, 1, 4);
    // create the graph given in above fugure
//    int V = 9;
//    struct Graph* graph = createGraph(V);
//    addEdge(graph, 0, 1, 4);
//    addEdge(graph, 0, 7, 8);
//    addEdge(graph, 1, 2, 8);
//    addEdge(graph, 1, 7, 11);
//    addEdge(graph, 2, 3, 7);
//    addEdge(graph, 2, 8, 2);
//    addEdge(graph, 2, 5, 4);
//    addEdge(graph, 3, 4, 9);
//    addEdge(graph, 3, 5, 14);
//    addEdge(graph, 4, 5, 10);
//    addEdge(graph, 5, 6, 2);
//    addEdge(graph, 6, 7, 1);
//    addEdge(graph, 6, 8, 6);
//    addEdge(graph, 7, 8, 7);
//
//    dijkstra(graph, 0);

    bool runApp = true;
    char input;


    while (runApp) {

        std::cin >> input;

        // check for program close
        if (input == 'x') runApp = false;
    }
    return 0;
}

