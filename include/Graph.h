//
// Created by glenn on 10/19/2017.
//

#ifndef SHORTEST_PATH_GRAPH_H
#define SHORTEST_PATH_GRAPH_H


#include "AdjacencyList.h"
#include <vector>

class Graph {
public:
    Graph(int numberOfVertices);
    int numOfVertices;
    std::vector<std::shared_ptr<AdjacencyList>> arrayOfLists;

    void addEdge(int src, int destination, int weight);
};


#endif //SHORTEST_PATH_GRAPH_H
