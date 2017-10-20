//
// Created by g on 10/19/17.
//

#include <memory>
#include "../include/MinimumHeap.h"
#include "../include/HeapNode.h"

MinimumHeap::MinimumHeap(int capacity) {
    this->pos = (int *) malloc(capacity * sizeof(int));
    this->size = 0;
    this->capacity = capacity;
    // TODO refactor to use vector of shared_ptr<HeapNode> instead of malloc
    this->array = (HeapNode **) malloc(capacity * sizeof(struct HeapNode *));
}

// TODO refactor to use std::shared_ptr<HeapNode>
void MinimumHeap::swapMinHeapNode(HeapNode **a, HeapNode **b) {
    HeapNode *newNode = *a;
    *a = *b;
    *b = newNode;
}

void MinimumHeap::doMinHeap(int idx) {
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < this->size &&
        this->array[left]->distance < this->array[smallest]->distance)
        smallest = left;

    if (right < this->size &&
        this->array[right]->distance < this->array[smallest]->distance)
        smallest = right;

    if (smallest != idx) {
        // The nodes to be swapped in min heap
        HeapNode *smallestNode = this->array[smallest];
        HeapNode *idxNode = this->array[idx];

        // Swap positions
        this->pos[smallestNode->v] = idx;
        this->pos[idxNode->v] = smallest;

        // Swap nodes
        this->swapMinHeapNode(&this->array[smallest], &this->array[idx]);

        this->doMinHeap(smallest);
    }
}

int MinimumHeap::isEmpty() {
    return this->size == 0;
}

HeapNode *MinimumHeap::extractMin() {

    if (this->isEmpty())
        return NULL;

    // Store the root node
    HeapNode* root = this->array[0];

    // Replace root node with last node
    HeapNode* lastNode = this->array[this->size - 1];
    this->array[0] = lastNode;

    // Update position of last node
    this->pos[root->v] = this->size-1;
    this->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --this->size;
    this->doMinHeap(0);

    return root;

}

void MinimumHeap::decreaseKey(int v, int dist) {

    // Get the index of v in  heap array
    int i = this->pos[v];

    // Get the node and update its dist value
    this->array[i]->distance = dist;

    // Travel up while the complete tree is not hepified.
    // This is a O(Logn) loop
    while (i && this->array[i]->distance < this->array[(i - 1) / 2]->distance)
    {
        // Swap this node with its parent
        this->pos[this->array[i]->v] = (i-1)/2;
        this->pos[this->array[(i-1)/2]->v] = i;
        this->swapMinHeapNode(&this->array[i],  &this->array[(i - 1) / 2]);

        // move to parent index
        i = (i - 1) / 2;
    }
}

bool MinimumHeap::isInMinHeap(int v) {
    if(this->pos[v] < this->size){
        return true;
    } else {
        return false;
    }
}

void MinimumHeap::printArray(int *dist, int n) {
    printf("Vertex    Distance from Source\n");
    for (int i = 0; i < n; ++i){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
