//
// Created by g on 10/19/17.
//

#ifndef SHORTEST_PATH_MINIMUMHEAP_H
#define SHORTEST_PATH_MINIMUMHEAP_H

#include <vector>
#include "HeapNode.h"

class MinimumHeap {
public:
    MinimumHeap(int capacity);

    int size;
    int capacity;
    int *pos;
    HeapNode **array;

    // TODO refactor to use shared_ptr<HeapNode>
    void swapMinHeapNode(HeapNode **a, HeapNode **b);

    // TODO refactor
    void doMinHeap(int idx);

    int isEmpty();

    HeapNode* extractMin();

    void decreaseKey(int v, int dist);

    bool isInMinHeap(int v);

    void printArray(int dist[], int n);
};


#endif //SHORTEST_PATH_MINIMUMHEAP_H
