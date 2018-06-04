#pragma once
#include <iostream>

enum decision {
    _insert,
    _pop,
    _free,
    _find,
    _save,
    _read,
    _quit,
    _vart
};


void menu();
void insert();
void pop();
void find();
void save();
void read();
void clear();
