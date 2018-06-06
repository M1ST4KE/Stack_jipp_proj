#pragma once


enum fieldOfStud {
    kier0,
    kier1,
    kier2,
    kier3,
    kier4,
    kier5,
    kier6
};

struct MY_STUDENT {
    std::string surname;
    int birthYear;
    enum fieldOfStud field;
};

void* myInit(std::string, int, fieldOfStud);
void myFree(void*);
void* myPush(std::string, int, fieldOfStud);
void myPrint(void*);
int mySearch(void*, void*);
void myBinSave(void*, std::fstream&);
void* myBinRead(std::fstream&);