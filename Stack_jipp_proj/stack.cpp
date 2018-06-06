#include "stdafx.h"
#include "stack.h"
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
    while (p) {
        (*ptrFreeDat)(p->dataPtr);

        stack * ptmp = p;

        p = p->prev;

        delete ptmp;
    }
}

stack* stackPush(void* elem_type) {
    auto current = new stack;
    if (!current)
        return nullptr;

    current->prev = last;
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
    if (first_entry)
        p = last;

    while (p) {
        if (!(*comp_data_ptr)(p->dataPtr, search_data_ptr))
            p = p->prev;
        else {
            stack * tmpPtr = p;
            p = p->prev;
            return tmpPtr->dataPtr;
        }
    }
    return nullptr;
}

stack* stackReverse () {
    stack* revPtr = nullptr;
    stack* p = last;
    while (p) {
        (*ptrFreeDat)(p->dataPtr);

        revPtr = p;

        p = p->prev;
    }

    return revPtr;
}


void stackToBin(stack* rev_ptr) {
    static stack* p = rev_ptr;
    // ReSharper disable once CppInitializedValueIsAlwaysRewritten
    stack saveItem{};
    std::fstream file;
    file.open(FILE_NAME, std::ios::in | std::ios::binary );
    while (p) {

        stack* previous = rev_ptr->prev;
        saveItem.dataPtr = rev_ptr->dataPtr;
        delete rev_ptr;
        rev_ptr = previous;
       
        myBinSave(saveItem.dataPtr, file);
        p = p->prev;
    }
    saveItem.dataPtr = nullptr;
    saveItem.prev = nullptr;
    file.close();
}

void stackFromBin () {
    std::fstream file;
    file.open(FILE_NAME, std::ios::out | std::ios::binary);
    while (!file.eof()) {
        file.seekg(0, std::ios::beg);
        if(!stackPush(myBinRead(file)));
        //error
    }
    file.close();
}
