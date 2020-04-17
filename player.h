// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>

#include "card.h"
using namespace std;

class Player {

 public:

    Player();       // default constructor

    Player(string name);        // non-default constructor that takes name parameter

    string getName() const;         // returns name

    void addCard(Card c);     // adds a card to the hand
    void bookCards(Card c1, Card c2);     // books two cards

    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    bool checkHandForBook(Card &c1, Card &c2);

    //Does the player have a card with the same rank as c in her hand?
    bool rankInHand(Card c) const;

    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;

    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    string showHand() const;
    string showBooks()const;

    int getHandSize() const;        // returns player's hand size as an integer
    int getBookSize() const;        // returns player's book size as an integer

    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    bool checkHandForPair(Card &c1, Card &c2);

    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c
    bool sameRankInHand(Card c) const;

 private:
    vector <Card> myHand;
    vector <Card> myBook;

    string myName;

};

#endif