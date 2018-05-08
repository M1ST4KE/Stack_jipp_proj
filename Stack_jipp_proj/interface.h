#pragma once
#include <iostream>

enum decision {
    _init,
    _free,
    _insert,
    _pop,
    _find,
    _save,
    _read,
    _quit
};

void mainLoop();