//
// Created on mac 10/05/2019.
//

#include <iostream>

#include "field.h"

using std::cout;
using std::cin;
using std::endl;

uint StepsNumber(uint, uint, uint);

int main() {
    cout << "Please, input field's length and width!" << endl;
    uint length = 0, width = 0;
    cin >> length >> width;

    assert(length > 0);
    assert(width > 0);

    cout << "Please, input coordinate between 1 and " << length << " inclusive!" << endl;
    uint coordinate = 0;
    cin >> coordinate;
    assert(coordinate > 0);
    while (true) {
        if (coordinate < 1 || coordinate > length) {
            cout << "You can input number only between 1 and " << length << " inclusive!" << endl;
            cin >> coordinate;
            assert(coordinate > 0);
            continue;
        } else break;
    }

    cout << "The number of steps is " << StepsNumber(coordinate, length, width) << "." << endl;

    return 0;
}