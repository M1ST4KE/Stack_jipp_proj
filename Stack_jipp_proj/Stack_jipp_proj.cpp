// Stack_jipp_proj.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "interface.h"
#include "stack.h"
#include "data.h"


int main(){

    stackInit(myFree);
    int dec;
    while (true) {
        menu();
        std::cin >> dec;
        switch (dec) {
        case _insert: insert();
            break;
        case _pop: pop();
            break;
        case _free: clear();
            break;
        case _find: find();
            break;
        case _save: save();
            break;
        case _read: read();
            break;
        case _quit: clear();
            return 0;
        default:
            std::cout << "Invalid decision";
        }
    } 
}

