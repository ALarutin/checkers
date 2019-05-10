//
// Created on 10/05/2019.
//

#include "field.h"

FieldGraph::FieldGraph(const uint _horizontalSize, const uint _verticalSize) :
        horizontalSize(_horizontalSize),
        verticalSize(_verticalSize),
        cardinality(_horizontalSize * _verticalSize),
        lastActiveEdg(_horizontalSize * (_verticalSize - 1) - 1),
        graphsLists(_horizontalSize * _verticalSize),
        kings(_horizontalSize) {
    addEdges(horizontalSize);
}

//Используя очередь, обходим весь граф.
//Если мы встали на ячейку "дамка", то записываем в массив, в соответственную ячейку +1.
uint FieldGraph::StepsNumber(uint crd) {
    uint coordinate = crd - 1;
    uint amount = 0;
    vector<uint> paths(horizontalSize);

    getKings(coordinate);

    queue<uint> queue;
    queue.push(coordinate);
    while (!queue.empty()) {
        uint last = queue.front();
        queue.pop();
        for (auto &i : graphsLists[last]) {
            uint temp = static_cast<uint>(i);
            if (temp > lastActiveEdg) {
                if (paths[temp - lastActiveEdg - 1] != 0) {
                    paths[temp - lastActiveEdg - 1]++;
                } else if (kings[temp - lastActiveEdg - 1]) {
                    paths[temp - lastActiveEdg - 1]++;
                    queue.push(temp);
                }
            } else {
                queue.push(temp);
            }
        }
    }
    //Обходим полученный массив путей, и суммируем количетсво путей.
    for (int i = 0; i < horizontalSize; ++i) {
        if (paths[i] != 0) {
            amount += paths[i];
        }
    }
    return amount;
}

//Обрабатываем все поля:
//- находим детей(поля на которые можно ходить);
//- формируем невзвешенный, ориентированный граф.
void FieldGraph::addEdges(uint hs) {
    for (uint i = 0; i < cardinality; ++i) {
        if (i == cardinality - hs) {
            break;
        }
        if (i % hs == 0) {
            addEdg(i, i + hs + 1);
        } else if ((i + 1) % hs == 0) {
            addEdg(i, i + hs - 1);
        } else {
            addEdg(i, i + hs - 1);
            addEdg(i, i + hs + 1);
        }
    }
}

void FieldGraph::addEdg(uint from, uint to) {
    graphsLists[from].push_back(to);
}

void FieldGraph::getKings(uint crd) {
    if (crd % 2 == horizontalSize % 2) {
        for (int i = 1; i < horizontalSize; i += 2) {
            kings[i] = true;
        }
    } else {
        for (int i = 0; i < horizontalSize; i += 2) {
            kings[i] = true;
        }
    }
}
