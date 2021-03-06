#include "stdafx.h"
#include "data.h"
#include "error.h"


static std::string kierunki[]{
    "kier0",
    "kier1",
    "kier2",
    "kier3",
    "kier4",
    "kier5",
    "kier6",
    "none"
};

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
    auto dataPtr = static_cast<MY_STUDENT*>(ptr);
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
        std::cout << "kierunek:      " << kierunki[currentPtr->field] << '\n';
        system("pause");
    } else  
        messageFunction(NO_DATA_TO_PRINT);
}

bool mySearch (void* curr_ptr, void* search_data_ptr) {
    auto currPtr = static_cast<MY_STUDENT*>(curr_ptr);
    auto searchDataPtr = static_cast<MY_STUDENT*>(search_data_ptr);
    if (currPtr->surname == searchDataPtr->surname)             // NOLINT(readability-simplify-boolean-expr)
        return true;                                            // NOLINT(readability-simplify-boolean-expr)
    return false;
}


void myBinSave(void* ptr, std::fstream& file) {
    auto dataPtr = static_cast<MY_STUDENT*>(ptr);
    size_t strSize = sizeof(char) * dataPtr->surname.size();

    file.write(reinterpret_cast<char*>(&strSize), sizeof(size_t));
    file.write(dataPtr->surname.c_str(), strSize);
    file.write(reinterpret_cast<char*>(&dataPtr->birthYear), sizeof(int));
    file.write(reinterpret_cast<char*>(&dataPtr->field), sizeof(enum fieldOfStud));
}

void* myBinRead ( std::fstream& file) {
    size_t strSize = 0;
    int year = 0;
    fieldOfStud field = vart;

    file.read(reinterpret_cast<char*>(&strSize), sizeof(size_t));

    auto surnameTmp = new char[strSize];
    file.read(surnameTmp, strSize);
    file.read(reinterpret_cast<char*>(&year), sizeof(int));
    file.read(reinterpret_cast<char*>(&field), sizeof(enum fieldOfStud));

    std::string surname;
    for (int i = 0; i < strSize; i++)
        surname += surnameTmp[i];

    return myInit(surname, year, field);
}
