#include "stdafx.h"
#include "stack.h"
#include "data.h"


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
    stackPush(dataPtr);
}

void pop() {
    stack tmp = stackPop();

}

void clear() {
    stackFree();
}