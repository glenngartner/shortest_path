//
// Created by g on 10/19/17.
//

#ifndef SHORTEST_PATH_DIJKSTRA_H
#define SHORTEST_PATH_DIJKSTRA_H


#include "Graph.h"

class Dijkstra {
public:
    static void generate(std::shared_ptr<Graph> graph, int src);
};


#endif //SHORTEST_PATH_DIJKSTRA_H
