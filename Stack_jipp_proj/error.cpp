#include "stdafx.h"
#include "stack.h"
#include "error.h"


static std::string my_error_messages[] = {
    "ERROR - Memory allocation error\n",
    "ERROR - File open failture\n",
    "ERROR - File error occured output unvaliable\n",
    "ERROR - File error occured input unvaliable\n",
    "Info - Stack empty, no item to pop\n",
    "Info - File empty, no item to read\n",
    "Info - File doesn't exist\n",
    "Info - No data to print\n",
    "Info - invalid decision\n"
};


MY_DECISION messageFunction(enum MY_MESSAGES message) {
    MY_DECISION returnValue = MY_CONTINUE;

    system("CLS");
    std::cout << my_error_messages[message];
    system("pause");

    if (my_error_messages[message][0] == 'E') {
        returnValue = MY_BREAK;
        criticalError(returnValue);
    }
    return returnValue;
}

void criticalError(int error_code) {
    stackFree();
    exit(error_code);
}

