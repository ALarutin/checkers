//
// Created on mac 10/05/2019.
//

#ifndef CHECKERS_FIELD_H
#define CHECKERS_FIELD_H

#include "list"

using std::list;

typedef unsigned uint;              //Используем не отрицательные значения.

struct cell {                       //Клетка, хранит в себе координату(только горизонтальную) и количетсво путей до нее.
    cell() = default;

    uint coordinate;                //Координата клетки.
    uint paths;                     //Колличество путей до клетки.
};

#endif //CHECKERS_FIELD_H

