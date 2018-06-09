#include "stdafx.h"
#include "stack.h"
#include "data.h"
#include "error.h"


static std::string strtab[] =
{
    "0 - push\n",
    "1 - pop\n",
    "2 - clear\n",
    "3 - find\n",
    "4 - save to file\n",
    "5 - read from file\n",
    "6 - quit\n"
};

void menu() {
    for (size_t i = 0; i < _vart; ++i) std::cout << strtab[i];

}

void insert() {
    std::string surname;
    int birthYear;
    int field;
    std::cout << "podaj nazwisko, rok urodzienia i kierunek studiow\n";
    std::cin >> surname >> birthYear >> field;
    void* dataPtr = myPush(surname, birthYear, static_cast<fieldOfStud>(field));
    if (!stackPush(dataPtr))
        messageFunction(ERROR_MEM_ALLOC);
}

void pop() {
    void* tmp = stackPop();
    myPrint(tmp);
    myFree(tmp);
}

void find() {
    std::cout << "podaj nazwisko do znalezienia\n";
    MY_STUDENT seakData {};
    std::cin >> seakData.surname;
    void* dataPtr = stackSearch(&seakData, mySearch, 1);

    if (dataPtr) {
        std::cout << "znaleziono: ";
        myPrint(dataPtr);

        while (dataPtr) {
            dataPtr = stackSearch(&seakData, mySearch, 0);
            if (dataPtr) {
                std::cout << "znaleziono: ";
                myPrint(dataPtr);
            }
        }
    } 
    else
    {
        std::cout << "nie znaleziono studenta o nazwisku: " << seakData.surname << "\n";
    }
  
}

void save() {
    stackToBin(myBinSave);
}

void read() {
    stackFromBin(myBinRead);
}

void clear() {
    stackFree();
}