#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>

#include "Card.h"
using namespace std;

class Player {

 public:

    Player();       // default constructor

    Player(string name);

    string getName() const;

    void addCard(Card c);     // adds a card to the hand
    void bookCards(Card c1, Card c2);     // books two cards

    bool checkHandForBook(Card &c1, Card &c2);

    bool rankInHand(Card c) const;

    Card chooseCardFromHand() const;

    bool cardInHand(Card c) const;

    Card removeCardFromHand(Card c);    // remove card from hand and return it to the caller

    string showHand() const;
    string showBooks()const;

    int getHandSize() const;
    int getBookSize() const;

    bool checkHandForPair(Card &c1, Card &c2);

    bool sameRankInHand(Card c) const;

 private:
    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};

#endif