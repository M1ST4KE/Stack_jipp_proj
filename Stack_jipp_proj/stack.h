#pragma once


struct stack {
    void* type;
    stack* prev;
};
typedef void(*freeData)(void *pdat);                        
typedef int (compData)(void * pcurData, void * pSearchData);


void stackInit(freeData);
void stackFree();
stack* stackPush(void*);
stack stackPop();
void* stackSearch(void*, compData, int);