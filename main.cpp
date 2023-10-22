#include <iostream>
#include <string>
#include <cstring>
#include "data_structures.h"
#include "util.h"
#include "heap.h"
#include <cstdio>

using namespace std;

int main (int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 4) {
        cout << "Usage: ./PJ2 <FileI> <FileO> flag" << endl;
        cout << "<FileI>    is the input file" << endl;
        cout << "<FileO>    is the output file" << endl;
        cout << "flag        is in {0, 1, 2, 3}" << endl;
        return 0;
    }

    // Check for correct flag
    int flag = stoi(argv[3]);
    if (flag < 0 || flag > 3) {
        cout << "Usage: ./PJ2 <FileI> <FileO> flag" << endl;
        cout << "<FileI>    is the input file" << endl;
        cout << "<FileO>    is the output file" << endl;
        cout << "flag        is in {0, 1, 2, 3}" << endl;
        return 0;
    }

    // Open files
    FILE *inFile = fopen(argv[1], "r");
    FILE *outFile = fopen(argv[2], "w");

    // Create heap
    HEAP *heap = new HEAP;
    heap->size = 0;
    heap->capacity = 0;
    heap->H = nullptr;
    heap->heapify_count = 0;

    // Read and execute instructions directly in the main loop
    char instruction[20];
    double key;
    int capacity, position;

    fscanf(stdin, "%s", instruction);

    while (true) {

        // check for end of file
        if (feof(stdin)) {
            break;
        }

        // Stop Instruction
        if (strcmp(instruction, "Stop") == 0) {
            printf("Instruction: Stop\n");
            break;
        }
        // Init <Capacity> Instruction
        else if (strcmp(instruction, "Init") == 0) {
            fscanf(stdin, "%d", &capacity);
            printf("Instruction: Init %d", capacity);
            heap->capacity = capacity;
            heap->H = new ELEMENT * [capacity+1];
        }
        // Insert <key> Instruction
        else if (strcmp(instruction, "Insertion") == 0) {
            fscanf(stdin, "%lf", &key);
            Insertion(heap, key, flag);
        }
        // ExtractMin Instruction
        else if (strcmp(instruction, "ExtractMin") == 0) {
            ExtractMin(heap, flag);
        }
        // DecreaseKey <Position> <Key>
        else if (strcmp(instruction, "DecreaseKey") == 0) {
            fscanf(stdin, "%d", &position);
            fscanf(stdin, "%lf", &key);
            DecreaseKey(heap, position, key);
        }
        else if (strcmp(instruction, "Write") == 0) {
            WriteInstruction(heap, argv[2], flag);
        }
        else if (strcmp(instruction, "Read") == 0) {
            ReadInstruction(heap, argv[1], flag);
        }
        else if (strcmp(instruction, "Print") == 0) {
            PrintInstruction(heap);
        }
        else {
            printf("Warning: Invalid instruction\n");
        }
    }

    // Close files
    fclose(inFile);
    fclose(outFile);

    // Clean up memory
    for (int i = 0; i < heap->size; i++) {
        delete heap->H[i];
    }
    delete[] heap->H;
    delete heap;

    return 0;
}
