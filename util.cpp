#include "data_structures.h"
#include "heap.h"
#include "util.h"
#include <iostream>
#include <cstdio>
using namespace std;

void PrintInstruction (HEAP *heap) {
    printf("Instruction: Print\n");
    if (heap == nullptr) {
        fprintf(stderr, "Error: heap is NUll\n");
        return;
    }
    printf("%d\n", heap->size);
    for (int i = 1; i <= heap->size; i++) {
        printf("%.6lf\n", heap->H[i]->key);
    }
}

void ReadInstruction (HEAP *heap, char* filename, int flag) {
    // if the heap is null print the following message to stderr "Error: heap is NULL"
    if(heap == nullptr){
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
    // if the heap is not null, then free the memory allocated to the heap
    FILE *file = fopen(filename, "r");
    // if the file is null print the following message to stderr "Error: file is NULL"
    if(file == nullptr){
        fprintf(stderr, "Error: file is NULL\n");
        return;
    }
    // If the file is opened successfully,
    // read the first integer from the file and store it in the variable size (n).
    int n;
    fscanf(file, "%d", &n);
    // if the capacity is less than or equal to zero,
    // print the following message to stderr "Error: invalid capacity"
    if(n <= 0){
        fprintf(stderr, "Error: invalid capacity\n");
        return;
    }
    // if the size is greater than the initialized capacity,
    // print the following message to stderr "Error: heap size larger than capacity"
    if (n > heap->capacity) {
        fprintf(stderr, "Error: heap size larger than capacity");
        fclose(file);
    }

    heap->size = n;
    heap->H = new ELEMENT*[n+1];
    heap->H[0] = nullptr;
    double key;
    for(int i = 1; i <= n; i++){
        fscanf(file, "%lf", &key);
        auto *element = new ELEMENT;
        element->key = key;
        heap->H[i] = element;
    }
    if (!isMinHeap(heap, n)) {
        fprintf(stderr, "Error: heap is not a min heap\n");
        return;
    }
    BuildHeap(heap);
    fclose(file);
}

void WriteInstruction (HEAP *heap, char* filename, int flag) {
    // check if null and print eror
    if(heap == nullptr){
        fprintf(stderr, "Error: heap is NULL\n");
        return;
    }
    // open file in write mode
    FILE *file = fopen(filename, "w");
    // check if null and print error
    if(file == nullptr){
        fprintf(stderr, "Error: file is NULL\n");
        return;
    }
    // write the size of the heap to the file as an integer
    fprintf(file, "%d\n", heap->size);
    // write the keys of the elements in the heap to the file with 6 decimal places
    for(int i = 1; i <= heap->size; i++){
        fprintf(file, "%.6lf\n", heap->H[i]->key);
    }
    fclose(file);
}
