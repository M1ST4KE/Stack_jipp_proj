#include "stdafx.h"
#include "data.h"


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

void myPrint ( void* data_ptr) {

    auto currentPtr = static_cast<MY_STUDENT*>(data_ptr);

    if (currentPtr) {
        std::cout << "nazwisko:      " << currentPtr->surname << '\n';
        std::cout << "rok urodzenia: " << currentPtr->birthYear << '\n';
        switch (currentPtr->field) {
        case 0:
            std::cout << "kier0\n";
            break;
        case 1:
            std::cout << "kier1\n";
            break;
        case 2:
            std::cout << "kier2\n";
            break;
        case 3:
            std::cout << "kier3\n";
            break;
        case 4:
            std::cout << "kier4\n";
            break;
        case 5:
            std::cout << "kier5\n";
            break;
        case 6:
            std::cout << "kier6\n";
            break;
        default:
            std::cout << "blad\n";
            break;
        }
    }
}

int mySearch (void* curr_ptr, void* search_data_ptr) {
    auto currPtr = static_cast<MY_STUDENT*>(curr_ptr);
    auto searchDataPtr = static_cast<MY_STUDENT*>(search_data_ptr);
    if (currPtr == searchDataPtr)
        return 1;
    return 0;
}


void myBinSave(void* ptr, std::fstream& output) {
    output.write(reinterpret_cast<char*>(ptr), sizeof(MY_STUDENT));
}

void* myBinRead ( std::fstream& file) {
    MY_STUDENT* data = nullptr;
    file.read(reinterpret_cast<char*>(data), sizeof(MY_STUDENT));
    return myInit(data->surname, data->birthYear, data->field);
}
