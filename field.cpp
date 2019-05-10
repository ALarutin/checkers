//
// Created by mac on 10/05/2019.
//

#include "field.h"

FieldGraph::FieldGraph(const size_t _horizontalSize, const size_t _verticalSize) :
        horizontalSize(static_cast<uint>(_horizontalSize)),
        verticalSize(static_cast<uint>(_verticalSize)),
        cardinality(static_cast<uint>(_horizontalSize * static_cast<uint>(_verticalSize))),
        graphsLists(_horizontalSize * _verticalSize),
        isKing(_horizontalSize) {
    addEdges(horizontalSize);
}

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
        for (int i = 0; i < horizontalSize; i += 2) {
            isKing[i] = true;
        }
    } else {
        for (int i = 1; i < horizontalSize; i += 2) {
            isKing[i] = true;
        }
    }
}
