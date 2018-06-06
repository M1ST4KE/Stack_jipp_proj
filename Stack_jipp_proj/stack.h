#pragma once


struct stack {
    void* dataPtr;
    stack* prev;
};

#define FILE_NAME "file.bin"

typedef void(*freeData)(void* pdat);                        
typedef int(compData)(void* type_ptr, void* search_data_ptr);



void stackInit(freeData);
void stackFree();
stack* stackPush(void*);
stack stackPop();
void* stackSearch(void*, compData, int);
stack* stackReverse();
void stackToBin();
void stackFromBin();