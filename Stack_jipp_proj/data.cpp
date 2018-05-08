#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "data.h"

void* myInit(std::string surname, int year, fieldOfStud field) {
    auto* pdat = static_cast<MY_STUDENT*>(malloc(sizeof(MY_STUDENT)));
    if (pdat) {
        pdat->surname = surname;
        pdat->birthYear = year;
        pdat->field = field;
    }
    return static_cast<void*>(pdat);
}

void myFree(void* ptr) {
    MY_STUDENT* pDat = static_cast<MY_STUDENT*>(ptr);
    if (pDat)
        free(pDat);
}

void* myPush(std::string surname, int year, fieldOfStud field) {
    return myInit(surname, year, field);
}