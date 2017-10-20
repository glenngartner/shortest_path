//
// Created by glenn on 10/19/2017.
//

#ifndef SHORTEST_PATH_NODE_H
#define SHORTEST_PATH_NODE_H


#include <memory>

class Node {
public:
    Node(int destination, int weight);
    int destination;
    int weight;
    std::shared_ptr<Node> next;
};


#endif //SHORTEST_PATH_NODE_H
