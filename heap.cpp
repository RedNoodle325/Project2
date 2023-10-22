#include "data_structures.h"
#include "heap.h"
#include <stdio.h>


//Heap starts at index 1

using namespace std;

// Return values;
int ParentIndex(int currentPosition){
    return (currentPosition - 1) / 2;
}

int leftIndex(int currentPosition){
    return 2 * currentPosition + 1;
}

int rightIndex(int currentPosition){
    return 2 * currentPosition + 2;
}

bool isNull(HEAP *heap){
    if(heap == nullptr){
        return true;
    }
    return false;
}

bool isEmpty(HEAP *heap){
    if(heap->size == 0){
        return true;
    }
    return false;
}

bool isFull(HEAP *heap){
    if(heap->size == heap->capacity){
        return true;
    }
    return false;
}

int getHeapifyCount (HEAP *heap) {
    return heap->heapify_count;
}

void resetHeapifyCount (HEAP *heap) {
    heap->heapify_count = 0;
}

void increaseHeapifyCount (HEAP *heap) {
    heap->heapify_count++;
}

void Heapify(HEAP *heap, int currentPosition) {
    int leftValue = leftIndex(currentPosition);
    int rightValue = rightIndex(currentPosition);
    int smallestKey;
    increaseHeapifyCount(heap);
    if (leftValue <= heap->size && heap->H[leftValue]->key < heap->H[currentPosition]->key) {
        smallestKey = leftValue;
    } else {
        smallestKey = currentPosition;
    }
    if (rightValue <= heap->size && heap->H[rightValue]->key < heap->H[smallestKey]->key) {
        smallestKey = rightValue;
    } else {
        smallestKey = currentPosition;
    }
    if (smallestKey != currentPosition) {
        ELEMENT* temp = heap->H[currentPosition];
        heap->H[currentPosition] = heap->H[smallestKey];
        heap->H[smallestKey] = temp;
        Heapify(heap, smallestKey);
    }
}

void BuildHeap(HEAP *heap) {
    for (int i = heap->size / 2; i >= 1; i--) {
        Heapify(heap, i);
    }
}

void ExtractMin(HEAP *heap, int flag) {
    printf("Instruction: ExtractMin");
    if (isNull(heap)) {
        fprintf(stderr, "Error: heap is NULL");
    }
    if (isEmpty(heap)) {
        fprintf(stderr, "Error: heap is empty");
    }
    double min = heap->H[1]->key;
    heap->H[1] = heap->H[heap->size];
    heap->size--;
    Heapify(heap, 1);
    if (flag == 1 || flag == 3) {
        int count = getHeapifyCount(heap);
        printf("Element with key %lf extracted from the heap\n", min);
        printf("Number of Heapify calls triggered by ExtractMin: %d\n", count);
        resetHeapifyCount(heap);
    }
}

void DecreaseKey(HEAP *heap, int position, double new_key) {
    printf("Instruction: DecreaseKey index %d, %lf", position, new_key);
    if (isNull(heap)) {
        fprintf(stderr, "Error: heap is NULL");
    }
    if (isEmpty(heap)) {
        fprintf(stderr, "Error: heap is empty");
    }
    //if position is out of bounds
    if(position <= 0 || position > heap->size){
        fprintf(stderr, "Invalid call to DecreaseKey");
    }
    //if new_key is less than current key
    if(new_key < heap->H[position]->key){
        heap->H[position]->key = new_key;
        // find the correct position for the element and swap it
        while(position > 0 && heap->H[ParentIndex(position)]->key > heap->H[position]->key){
            ELEMENT* temp = heap->H[position];
            heap->H[position] = heap->H[ParentIndex(position)];
            heap->H[ParentIndex(position)] = temp;
            position = ParentIndex(position);
        }
    }
}

void Insertion(HEAP *heap, double key, int flag) {
    printf("Instruction: Insertion %lf", key);
    //if heap is null
    if(isNull(heap)){
        fprintf(stderr, "Error: heap is NULL");
    }
    //if heap is full
    if(isFull(heap)){
        fprintf(stderr, "Error: heap is full");
    }

    heap->size++;
    heap->H[heap->size]->key = key;
    DecreaseKey(heap, heap->size, key);

    if (flag == 2 || flag == 3) {
        printf("Location of the newly inserted element: %d\n", heap->size);
    }
 }

bool isMinHeap(HEAP *heap, int size) {
    for (int i = 1; i <= size / 2; i++) {
        if (2 * i <= size && heap->H[i]->key > heap->H[2 * i]->key) return false;
        if (2 * i + 1 <= size && heap->H[i]->key > heap->H[2 * i + 1]->key) return false;
    }
    return true;
}