#include "stdafx.h"
#include "stack.h"
#include <iostream>
#include <cstdlib>
#include "data.h"

static stack* first = nullptr;
freeData ptrFreeDat;

void stackInit(freeData p_free_data) {
    first = nullptr;
    ptrFreeDat = p_free_data;
}

void stackFree() {
    stack* p = first;
    stack* ptmp = nullptr;
    while (p) {
        (*ptrFreeDat)(p->type);

        ptmp = p;

        p = p->prev;

        free(ptmp);
    }
}

stack* stackPush(void* elem_type) {
    auto* current = static_cast<stack*>(malloc(sizeof(stack)));
    if (current)
        return nullptr;

    current->prev = nullptr;

    if (!first)
        first = current;

    current->type = elem_type;

    stack* p = first;
    while (p->prev)
        p = p->prev;

    if (first != current)
        p->prev = current;

    return current;
}

stack stackPop() {
    stack last {};
    if (!first) {
        last.type = nullptr;
        last.prev = nullptr;
    }
    return last;
}

void* stackSearch(void* search_data_ptr, compData comp_data_ptr, int first_entry) {
    static stack* p;
    stack* tmpPtr = nullptr;

    if (first_entry)
        p = first;

    while (p) {
        if (!(*comp_data_ptr)(p->type, search_data_ptr))
            p = p->prev;
        else {
            tmpPtr = p;
            p = p->prev;
            return tmpPtr->type;
        }
    }
    return nullptr;
}