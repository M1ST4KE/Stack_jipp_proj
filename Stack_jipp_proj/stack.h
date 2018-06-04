#pragma once
#include <fstream>


struct stack {
    void* dataPtr;
    stack* prev;
};
typedef void(*freeData)(void* pdat);                        
typedef int(compData)(void* type_ptr, void* search_data_ptr);
typedef void(binSave)(void* type_ptr, std::ofstream&);


void stackInit(freeData);
void stackFree();
stack* stackPush(void*);
stack stackPop();
void* stackSearch(void*, compData, int);
void stackToBin();
