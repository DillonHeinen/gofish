#include <iostream>
#include "card.h"

using namespace std;

int main() {
    Card s(2, Card::spades);
    Card h;

    cout << (s != h) << endl;
    cout << s << " " << h << endl;

    return 0;
}