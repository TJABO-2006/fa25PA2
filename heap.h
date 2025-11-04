//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {

        data[size] = idx;
        upheap(size, weightArr); // Restore heap order
        size++;

    }

    int pop(int weightArr[]) {
        // Replace root with last element, then call downheap()
        if (size == 0) {
            return 0; // No popping if empty
        }
        int minimumIndex = data[0];
        size--;                         // Decrease heap size
        data[0] = data[size];           // Moves the last element to front (root)
        downheap(0, weightArr);     // Restore heap order
        return minimumIndex;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {

            int parent = (pos - 1) / 2; // Parent index

            if (weightArr[data[pos]] >= weightArr[data[parent]])
                break;
            swap(data[pos], data[parent]); // swaps if smaller
            pos = parent;                             // Move upward

        }
    }

    void downheap(int pos, int weightArr[]) {

        while (pos < size) {
            int left = 2 * pos + 1;  // Left child
            int right = 2 * pos + 2; // Right child
            int smallest = pos;      // Initially assumes parent is smallest

            // Find smallest among parent and children
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]])
                smallest = left;

            if (right < size && weightArr[data[right]] < weightArr[data[smallest]])
                smallest = right;

            if (smallest == pos) break; // stops if parent is smallest

            // Swap with smaller child and continue
            swap(data[pos], data[smallest]);
            pos = smallest;

        }
    }
};

#endif