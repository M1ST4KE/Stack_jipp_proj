#include "stdafx.h"
#include "stack.h"
#include "error.h"


static stack* last = nullptr;
freeData ptrFreeDat;
std::streampos write_pos = 0;

void stackInit(freeData p_free_data) {
    last = nullptr;
    ptrFreeDat = p_free_data;
}

//funkcja zwalnia stos i czyści pamięć poszczególnych elementów
void stackFree() {
    stack* p = last;
    while (p) {
        (*ptrFreeDat)(p->dataPtr);

        stack * ptmp = p;

        p = p->prev;

        delete ptmp;
    }
    last = nullptr;
}

//funkcja dodaje na stos utworzony element
stack* stackPush(void* data_ptr) {
    auto current = new stack;
    if (!current)
        return nullptr;

    current->prev = last;
    current->dataPtr = data_ptr;

    last = current;
    return current;
}

//funkcja usuwa ostatni element ze stosu i zwraca jego zawartość
void* stackPop() {
    void* popData = nullptr;
    if (!last) {
        return popData;
    }
    popData = last->dataPtr;
    stack* dataPtr = last->prev;
    delete last;
    last = dataPtr;

    return popData;
}

//funkcja wyszukująca dany element w stosie
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

//funkcja odwracająca stos
static stack* stackReverse () {
     void* tmp = stackPop();
     auto stackReverse = new stack;
     //tworzę pierwszy element odwróconego stosu
     stackReverse->prev = nullptr;
     stackReverse->dataPtr = tmp;
     //dodaję kolejne elementy do odwróconego stosu
     while ((tmp = stackPop())) {
         auto stackTmp = new stack;
         stackTmp->dataPtr = tmp;
         stackTmp->prev = stackReverse;
         stackReverse = stackTmp;
     }

    // zwracam wskaźnik do pierwszego elementu odwróconego stosu
     return stackReverse;

}

//funkcja zapisująca elementy stosu do pliku binarnego
void stackToBin(void(*bin_save)(void*, std::fstream& file)) {
    void* dataToSave;

    if (!last) {
        messageFunction(STACK_EMPTY);
        return;
    }

    //otwieram nowy plik
    std::fstream file;

    file.open(MY_FILE_NAME, std::ios::out | std::ios::binary | std::ios::app);

    if (!file.is_open())
        messageFunction(ERROR_FILE_OPEN);

    if (!file.good())
        messageFunction(ERROR_FILE_OUT_UNVALIABLE);

    file.seekp(write_pos);
    stack* revPtr = stackReverse();
    //zapisuję do pliku
    while (revPtr) {

        stack* previous = revPtr->prev;
        dataToSave = revPtr->dataPtr;
        delete revPtr;
        revPtr = previous;
       
        bin_save(dataToSave, file);
    }
    dataToSave = nullptr;
    write_pos = file.tellp();
    file.close();
}

void stackFromBin (void*(*bin_read)(std::fstream&)) {

    //otwieram plik
    std::fstream file;
    file.open(MY_FILE_NAME, std::ios::in | std::ios::binary);

    if (!file.good())
        messageFunction(ERROR_FILE_IN_UNVALIABLE);

    if (!file.is_open())
        messageFunction(FILE_NOT_EXIST);

    //sprawdzam, czy plik nie jest pusty
    if (![&file]()->bool{
        file.seekg(0, std::ios::end);
        return write_pos = file.tellg(); }()) {
        messageFunction(FILE_EMPTY);
    } else {
        file.seekg(0, std::ios::beg);
        while (file.tellg() != write_pos) {
            if (!stackPush(bin_read(file)))
                messageFunction(ERROR_MEM_ALLOC);
        }
    }
    file.close();

#ifndef DEBUG_FLAG
    //usuwam plik po wczytaniu zawartości
    std::remove(MY_FILE_NAME);
#endif

}
