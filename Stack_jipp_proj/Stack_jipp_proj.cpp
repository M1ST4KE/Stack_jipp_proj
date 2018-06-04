// Stack_jipp_proj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack.h"
#include "data.h"


int main()
{
    stackInit(myFree);
    int dec;
    while (true) {
        menu();
        std::cin >> dec;
        switch (dec) {
        case _insert: insert();
            break;
        case _pop:
            break;
        case _free: clear();
            break;
        case _find:
            break;
        case _save:
            break;
        case _read:
            break;
        case _quit: clear();
            return 0;
        default:
            std::cout << "Invalid decision";
        }
    } 
}

