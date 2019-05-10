//
// Created on 10/05/2019.
//

#ifndef CHECKERS_FIELD_H
#define CHECKERS_FIELD_H

#include "vector"
#include "queue"

using std::queue;
using std::vector;

typedef unsigned int uint;              //Используем не отрицательные значения.

class FieldGraph {
public:
    FieldGraph(size_t, size_t);         //Конструктор

    uint StepsNumber(uint);             //Метод для подсчета количества путей.

private:

    void addEdges(uint);                //Метод для формирования графа.

    void addEdg(uint, uint);            //Метод для добавление узла графа.

    void getKings(uint);                //Метод для определения массива полей, на которых мы станет "дамкой".

    vector<vector<int>> graphsLists;    //Граф.
    vector<bool> kings;                 //Массив полей, на которых мы станет "дамкой"
    uint cardinality;                   //Количетсво полей.
    uint horizontalSize;                //Количество полей по горизонтали.
    uint verticalSize;                  //Количество полей по вертикали.
    uint lastActiveEdg;                 //Номер последнего поля на предпоследней линии.
};

#endif //CHECKERS_FIELD_H

