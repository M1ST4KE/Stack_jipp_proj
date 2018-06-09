#pragma once

//#define DEBUG_FLAG
#define MY_FILE_NAME "file.bin"

struct stack {
    void* dataPtr;
    stack* prev;
};



typedef void(*freeData)(void* pdat);                        
typedef bool(compData)(void* data_ptr, void* search_data_ptr);



void stackInit(freeData);
void stackFree();
stack* stackPush(void*);
void* stackPop();
void* stackSearch(void*, compData, int);
static stack* stackReverse();
void stackToBin(void(*)(void*, std::fstream&));
void stackFromBin(void*(*)(std::fstream&));