#ifndef HEAP_H
#define HEAP_H


int ParentIndex(int currentPosition);
int leftKey(int currentPosition);
int rightIndex(int currentPosition);
bool isNull(HEAP *heap);
bool isEmpty(HEAP *heap);
bool isFull(HEAP *heap);
void Heapify(HEAP *heap, int currentPosition);
void BuildHeap(HEAP *heap);
void ExtractMin(HEAP *heap, int flag);
void DecreaseKey(HEAP *heap, int position, double new_key);
void Insertion(HEAP *heap, double key, int flag);
bool isMinHeap(HEAP *heap, int size);


#endif // HEAP_H