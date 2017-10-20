//
// Created by glenn on 10/19/2017.
//

#include "../include/Graph.h"

Graph::Graph(int numberOfVertices) {
    this->numOfVertices = numberOfVertices;
    // Initialize empty adjacency list by making head == nullptr
    for (int i = 0; i < numberOfVertices; i++) {
        std::shared_ptr<AdjacencyList> list = std::make_shared<AdjacencyList>();
        this->arrayOfLists.push_back(list);
        this->arrayOfLists[i]->head = nullptr;
    }
}

void Graph::addEdge(int src, int destination, int weight) {
    // create a new node
    std::shared_ptr<Node> newNode = std::make_shared<Node>(destination, weight);
    // assign the next value of the new node the value of head from the source list vector
    newNode->next = this->arrayOfLists[src]->head;
    this->arrayOfLists[src]->head = newNode;

    // since the graph is undirected, add an edge from the dest to the src also
    std::shared_ptr<Node> newNode2 = std::make_shared<Node>(src, weight);
    newNode2->next = this->arrayOfLists[destination]->head;
    this->arrayOfLists[destination]->head = newNode2;
}
