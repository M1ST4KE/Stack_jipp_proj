#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "data.h"
#include <fstream>


#pragma warning (disable : 4996)

void* myInit(std::string surname, int year, fieldOfStud field) {
    auto dataPtr = new MY_STUDENT;
    if (dataPtr) {
        dataPtr->surname = surname;
        dataPtr->birthYear = year;
        dataPtr->field = field;
    }
    return static_cast<void*>(dataPtr);
}

void myFree(void* ptr) {
    auto* dataPtr = static_cast<MY_STUDENT*>(ptr);
    delete dataPtr;
}

void* myPush(std::string surname, int year, fieldOfStud field) {
    return myInit(surname, year, field);
}

void myPrint ( MY_STUDENT* ) {
    
}


void binSave(void* ptr, std::ofstream& output) {
    int type = 1;
    output.write(reinterpret_cast<char*>(&type), sizeof(int));

    auto* curData = static_cast<MY_STUDENT*>(ptr);
    output.write(reinterpret_cast<char*>(curData), sizeof(MY_STUDENT));


}
