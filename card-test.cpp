#include <iostream>
#include "card.h"
using namespace std;

int main() {
    Card card("Red", 5);
    Card sameColor("Red", 2);
    Card sameNumber("Blue", 5);
    Card noMatch("Blue", 2);

    cout << card.getColor() << endl;
    cout << card.getValue() << endl;
    cout << card.toString() << endl;

    cout << boolalpha;
    cout << card.canPlay(sameColor) << endl;
    cout << card.canPlay(sameNumber) << endl;
    cout << card.canPlay(noMatch) << endl;

    return 0;
}