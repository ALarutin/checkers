//
// Created by mac on 10/05/2019.
//

#ifndef CHECKERS_FIELD_H
#define CHECKERS_FIELD_H

#include "vector"
#include "queue"

using std::queue;
using std::vector;

typedef unsigned int uint;

class FieldGraph {
public:
    FieldGraph(size_t, size_t);

private:
    void addEdges(uint);

    void addEdg(uint, uint);

    vector<vector<uint>> graphsLists;
    vector<bool> isKing;
    uint cardinality;
    uint horizontalSize;
    uint verticalSize;
};

#endif //CHECKERS_FIELD_H

