// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph

#include <iostream>
#include <memory>
#include "../include/Graph.h"
#include "../include/Dijkstra.h"


int main()
{

    std::shared_ptr<Graph> graph = std::make_shared<Graph>(9);
    graph->addEdge(0, 1, 4);
    graph->addEdge(0, 7, 8);
    graph->addEdge(1, 2, 8);
    graph->addEdge(1, 7, 11);
    graph->addEdge(2, 3, 7);
    graph->addEdge(2, 8, 2);
    graph->addEdge(2, 5, 4);
    graph->addEdge(3, 4, 9);
    graph->addEdge(3, 5, 14);
    graph->addEdge(4, 5, 10);
    graph->addEdge(5, 6, 2);
    graph->addEdge(6, 7, 1);
    graph->addEdge(6, 8, 6);
    graph->addEdge(7, 8, 7);
    Dijkstra::generate(graph, 0);

    bool runApp = true;
    char input;


    while (runApp) {

        std::cin >> input;

        // check for program close
        if (input == 'x') runApp = false;
    }
    return 0;
}

