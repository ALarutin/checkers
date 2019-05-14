//
// Created on mac 10/05/2019.
//

#include "field.h"

FieldGraph::FieldGraph(const uint _horizontalSize, const uint _verticalSize) :
        horizontalSize(_horizontalSize),
        verticalSize(_verticalSize) {}

//Используем 2 списка (почему список, а не очередь, потому что в одном случае нужно доставть элемент не с front, а с back):
//- обходим линию за линией, храним только данный предыдущей и нынешней линии;
//- сохранием в "клетке"(cell) колличество ходов до этой клетке.
uint FieldGraph::StepsNumber(uint coordinate) {

    if (horizontalSize == 1 || verticalSize == 1) {
        return 0;
    }

    cell start{coordinate - 1, 1};

    list<cell> lastLine;
    lastLine.push_back(start);                                      //Заполянем список первой клеткой.

    for (uint i = 1; i < verticalSize; i++) {
        list<cell> thisLine;
        while (!lastLine.empty()) {

            cell last = lastLine.front();
            lastLine.pop_front();

            cell nextLeft{last.coordinate - 1};
            if (!thisLine.empty()) {                                //Проверяем, если список не пуст,
                nextLeft = thisLine.back();                         //то у этой клетки больше 1 родителя,
                thisLine.pop_back();
            }
            nextLeft.paths += last.paths;                           //и нужно прибавить новое количетсво путей.

            cell nextRight{last.coordinate + 1};
            nextRight.paths += last.paths;

            if (last.coordinate == 0) {
                thisLine.push_back(nextRight);
            } else if (last.coordinate == horizontalSize - 1) {
                thisLine.push_back(nextLeft);
            } else {
                thisLine.push_back(nextLeft);
                thisLine.push_back(nextRight);
            }
        }
        lastLine = thisLine;
    }

    uint steps = 0;
    while (!lastLine.empty()) {                                     //Обходим полученный в конце список, суммируя все пути.
        cell last = lastLine.front();
        lastLine.pop_front();
        steps += last.paths;
    }
    return steps;
}




