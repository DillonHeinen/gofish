#include "time.h"
#include "deck.h"

using namespace std;

Deck::Deck() {

    srand(time(0));

    for(int i = 0; i < 13; i++) {       // spades come first in deck
        myCards[i] = Card(i + 1, Card::spades);
    }
    for(int i = 13; i < 26; i++) {      // then hearts
        myCards[i] = Card(i + 1, Card::hearts);
    }
    for(int i = 26; i < 39; i++) {      // then diamonds
        myCards[i] = Card(i + 1, Card::diamonds);
    }
    for(int i = 39; i < 52; i++) {      // then clubs
        myCards[i] = Card(i + 1, Card::clubs);
    }

}

void Deck::shuffle() {

    for(int i = 0; i < SIZE*2; i++) {
        unsigned int num1 = rand() % SIZE;
        unsigned int num2 = rand() % SIZE;

        Card temp = myCards[num1];
        myCards[num1] = myCards[num2];
        myCards[num2] = temp;
    }

}

Card Deck::dealCard() {

    while(myIndex < 52) {
        myIndex++;
        return myCards[myIndex - 1];
    }

}

int Deck::size() const {
    return SIZE - myIndex;
}
