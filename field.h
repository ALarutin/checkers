//
// Created on mac 10/05/2019.
//

#ifndef CHECKERS_FIELD_H
#define CHECKERS_FIELD_H

#include "vector"
#include "list"
#include "map"

using std::map;
using std::list;
using std::vector;
using std::pair;

typedef unsigned uint;                  //Используем не отрицательные значения.

class FieldGraph {
public:
    FieldGraph(uint, uint);             //Конструктор

    uint StepsNumber(uint);             //Метод для подсчета количества путей.

private:
    struct cell {                       //Клетка, хранит в себе координату(только горизонтальную) и количетсво путей до нее.
        cell() = default;

        uint coordinate;                //Координата клетки.
        uint paths;                     //Колличество путей до клетки.
    };

    uint horizontalSize;                //Количество полей по горизонтали.
    uint verticalSize;                  //Количество полей по вертикали.
};

#endif //CHECKERS_FIELD_H

