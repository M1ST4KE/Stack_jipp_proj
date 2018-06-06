#include "stdafx.h"
#include "stack.h"

void criticalError(int error_code) {
    stackFree();
    exit(error_code);
}
