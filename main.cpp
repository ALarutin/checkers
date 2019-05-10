#include <iostream>

#include "field.h"

using std::cout;
using std::cin;

int main() {
    cout << "Please, input field's length and width!\n";
    size_t length = 0, width = 0;

    cin >> length >> width;

    FieldGraph field(length, width);

    return 0;
}
