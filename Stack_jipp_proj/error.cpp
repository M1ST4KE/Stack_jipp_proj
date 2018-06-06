#include "stdafx.h"
#include "stack.h"
#include "error.h"


static std::string my_error_messages[] = {
    "ERROR - Memory allocation error\n",
    "ERROR - File open failture\n",
    "ERROR - File error occured I/O unvaliable\n",
    "Info - Stack empty, no item to pop\n",
    "Info - File empty, no item to read\n",
    "Info - No data to print\n"
};


MY_DECISION messageFunction(enum MY_MESSAGES message) {
    MY_DECISION returnValue = MY_CONTINUE;

    std::cout << my_error_messages[message];

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

