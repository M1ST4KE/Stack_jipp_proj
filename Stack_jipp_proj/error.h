#pragma once

enum MY_DECISION {
    MY_BREAK,
    MY_CONTINUE
};

enum MY_MESSAGES {
    ERROR_MEM_ALLOC,
    ERROR_FILE_OPEN,
    ERROR_FILE_IO_UNVALIABLE,
    STACK_EMPTY,
    FILE_EMPTY,
    NO_DATA_TO_PRINT,
    MY_MESSAGES_TOT
};

MY_DECISION messageFunction(MY_MESSAGES);
void criticalError(int);