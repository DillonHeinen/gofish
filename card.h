#ifndef CARD
#define CARD

#include <iostream>
#include <string>
using namespace std;

class Card {
private:

    int myRank;
    int mySuit;

public:

    enum Suit {spaces, hearts, diamonds, clubs};

    Card();
    Card(int rank, Suit s);

    string toString()               const;      // return string version e.g. Ac 4h Js
    bool sameSuitAs(const Card &c)  const;      // true if suit same as c
    int getRank()                   const;      // return rank, 1, ..., 13
    string suitString(Suit s)       const;      // return "s", "h", ...

    string rankString(int r)        const;      // return "A", "2", ..., "Q"

    bool operator == (const Card &rhs) const;
    bool operator != (const Card &rhs) const;

};

ostream &operator <<(ostream &out, const Card &c);

#endif