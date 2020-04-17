#include "card.h"

using namespace std;

Card::Card() {

    myRank = 1;
    mySuit = spades;

}

Card::Card(int rank, Suit s) {

    myRank = rank;
    mySuit = s;

}

string Card::toString() const {

    string rank;
    switch(myRank) {
        case 1:
            rank = "A";
            break;
        case 11:
            rank = "J";
            break;
        case 12:
            rank = "Q";
            break;
        case 13:
            rank = "K";
            break;
        default:
            rank = to_string(myRank);
    }

    string suit;
    switch(mySuit) {
        case spades:
            suit = "s";
            break;
        case hearts:
            suit = "h";
            break;
        case diamonds:
            suit = "d";
            break;
        case clubs:
            suit = "c";
            break;
    }

    return rank + suit;
}

bool Card::sameSuitAs(const Card &c) const {

    return (this->mySuit == c.mySuit);

}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {

    string suit;
    switch (s) {
        case spades:
            suit = "s";
            break;
        case hearts:
            suit = "h";
            break;
        case diamonds:
            suit = "d";
            break;
        case clubs:
            suit = "c";
            break;
    }
    return suit;
}

string Card::rankString(int r) const {

    string rank;
    switch(myRank) {
        case 1:
            rank = "A";
            break;
        case 11:
            rank = "J";
            break;
        case 12:
            rank = "Q";
            break;
        case 13:
            rank = "K";
            break;
        default:
            rank = to_string(myRank);
    }
    return rank;
}

bool Card::operator == (const Card &rhs) const {

    return (this->myRank == rhs.myRank) && (this->mySuit == rhs.mySuit);

}

bool Card::operator != (const Card &rhs) const {

    return (this->myRank != rhs.myRank) || (this->mySuit != rhs.mySuit);

}

ostream &operator << (ostream &out, const Card &c) {

    out << c.toString();
    return out;

}