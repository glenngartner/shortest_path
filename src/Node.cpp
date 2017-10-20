//
// Created by glenn on 10/19/2017.
//

#include "../include/Node.h"

Node::Node(int destination, int weight) {
    this->destination = destination;
    this->weight = weight;
    this->next = nullptr;
}
