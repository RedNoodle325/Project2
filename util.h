#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"
#include "heap.h"

void PrintInstruction (HEAP *heap);
void ReadInstruction (HEAP *heap, char* filename, int flag);
void WriteInstruction (HEAP *heap, char* filename, int flag);
void freeHeap (HEAP *heap);

#endif // UTIL_H