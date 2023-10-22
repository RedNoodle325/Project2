// data_structures.h
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
struct ELEMENT {
    double key;
};

struct HEAP {
    int capacity;
    int size;
    ELEMENT** H; // Array of pointers to ELEMENT
    int heapify_count;
};
#endif // DATA_STRUCTURES_H