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
        (*ptrFreeDat)(p->dataPtr);

        ptmp = p;

        p = p->prev;

        delete ptmp;
    }
}

stack* stackPush(void* elem_type) {
    auto current = new stack;
    if (current)
        return nullptr;

    current->prev = nullptr;
    current->dataPtr = elem_type;

    last = current;
    return current;
}

stack stackPop() {
    stack popItem {};
    if (!last) {
        popItem.dataPtr = nullptr;
        popItem.prev = nullptr;
    } else {
        stack* previous = last->prev;
        popItem.dataPtr = last->dataPtr;
        delete last;
        last = previous;
    }
    return popItem;
}

void* stackSearch(void* search_data_ptr, compData comp_data_ptr, int first_entry) {
    static stack* p;
    stack* tmpPtr = nullptr;

    if (first_entry)
        p = last;

    while (p) {
        if (!(*comp_data_ptr)(p->dataPtr, search_data_ptr))
            p = p->prev;
        else {
            tmpPtr = p;
            p = p->prev;
            return tmpPtr->dataPtr;
        }
    }
    return nullptr;
}

/*void stackToBin(binSave write_bin) {
    static stack* p;
    std::ofstream output;
    output.open("output.bin", std::ios::binary);
    while (p) {
        (*write_bin)(p->dataPtr, output);
        p = p->prev;
    }
    //todo oprogramować zapis dla typu student
    output.close();
}
*/