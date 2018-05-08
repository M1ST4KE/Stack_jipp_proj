#pragma once
#include <string>


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

void* myInit(char*, int, fieldOfStud);
void myFree(void*);
void* myPush(char*, int, fieldOfStud);