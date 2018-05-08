#include "stdafx.h"
#include "stack.h"
#include <iostream>
#include <cstdlib>
#include "data.h"
#include <fstream>

static stack* last = nullptr;
freeData ptrFreeDat;

void stackInit(freeData p_free_data) {
    last = nullptr;
    ptrFreeDat = p_free_data;
}

void stackFree() {
    stack* p = last;
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

    if (!last)
        last = current;

    current->type = elem_type;

    stack* p = last;
    while (p->prev)
        p = p->prev;

    if (last != current)
        p->prev = current;

    return current;
}

stack stackPop() {
    stack popItem {};
    if (!last) {
        popItem.type = nullptr;
        popItem.prev = nullptr;
    }
    return popItem;
}

void* stackSearch(void* search_data_ptr, compData comp_data_ptr, int first_entry) {
    static stack* p;
    stack* tmpPtr = nullptr;

    if (first_entry)
        p = last;

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

void stackToBin(binSave write_bin) {
    static stack* p;
    std::ofstream output;
    output.open("output.bin", std::ios::binary);
    while (p) {
        (*write_bin)(p->type);
        p = p->prev;
    }
    //todo oprogramować zapis dla typu student
    output.close();
}