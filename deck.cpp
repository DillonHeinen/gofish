#include <ctime>
#include <cstdlib>
#include "deck.h"

using namespace std;

Deck::Deck() {          // fills deck using for loops to add in suit order
    myIndex = 0;
    srand(time(0));

    for(int i = 0; i < 13; i++) {       // spades come first in deck
        myCards[i] = Card(i + 1, Card::spades);
    }
    for(int i = 0; i < 13; i++) {      // then hearts
        myCards[i + 13] = Card(i + 1, Card::hearts);
    }
    for(int i = 0; i < 13; i++) {      // then diamonds
        myCards[i + 26] = Card(i + 1, Card::diamonds);
    }
    for(int i = 0; i < 13; i++) {      // then clubs
        myCards[i + 39] = Card(i + 1, Card::clubs);
    }

}

void Deck::shuffle() {

    for(int i = 0; i < SIZE*2; i++) {           // switches two cards SIZE*2 times
        unsigned int num1 = rand() % SIZE;
        unsigned int num2 = rand() % SIZE;

        Card temp = myCards[num1];
        myCards[num1] = myCards[num2];
        myCards[num2] = temp;
    }

}

Card Deck::dealCard() {            // returns top card on deck and increments index
    if(myIndex < 52) {
        myIndex++;
        return myCards[myIndex - 1];
    }
    else {
        return myCards[0];
    }
}

int Deck::size() const {        // returns number of cards by using index location
    return SIZE - myIndex;
}