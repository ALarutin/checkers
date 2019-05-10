#include <iostream>

#include "field.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Please, input field's length and width!" << endl;
    size_t length = 0, width = 0;
    cin >> length >> width;

    FieldGraph field(length, width);

    cout << "Please, input coordinate between 1 and " << length << "!" << endl;
    uint coordinate = 0;
    cin >> coordinate;
    while (true) {
        if (coordinate < 1 || coordinate > length ) {
            cout << "You can input number only between 1 and " << length << "!" << endl;
            cin >> coordinate;
            continue;
        } else break;
    }

    cout << "The number of steps is " << field.StepsNumber(coordinate) << "." << endl;

    return 0;
}
