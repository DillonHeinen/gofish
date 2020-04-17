#include "player.h"

using namespace std;

Player::Player() {          // constructor with anonymous name
    myName = "Anonymous";
}

Player::Player(string name) {       // constructor with name specified
    myName = name;
}

string Player::getName() const {        // returns player name
    return myName;
}

void Player::addCard(Card c) {      // fills myHand vector with card from parameter
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {          // fills myBook vector with cards from parameter
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {     // uses two for loops to check for matching ranks
    vector <Card>::iterator iter1, iter2;

    for(iter1 = myHand.begin(); iter1 < myHand.end(); iter1++) {
        for(iter2 = myHand.begin(); iter2 < myHand.end(); iter2++) {
            if(iter1->sameSuitAs(*iter2) != true) {         // filters if iter1 and iter2 are the same
                if(iter1->getRank() == iter2->getRank()) {
                    c1 = *iter1;
                    c2 = *iter2;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const {         // iterates through cards and checks if any have matching rank
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if(iter->getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {           // picks a random card to ask if the other player has
    unsigned int choice = rand() % myHand.size();
    return myHand.at(choice);
}

bool Player::cardInHand(Card c) const {
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if(iter->getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {           // finds card of matching rank and removes it
    Card yoink;
    for(vector <Card>::iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if((iter->getRank() == c.getRank())) {      // ranks are equal
            yoink = *iter;
            myHand.erase(iter);
            return yoink;
        }
    }
    return yoink;
}

string Player::showHand() const {
    string out;
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        out = out + iter->toString() + ", ";
    }
    out = out + "\b" + "\b" + "  ";
    return out;
}

string Player::showBooks() const {
    string out;
    for(vector <Card>::const_iterator iter = myBook.begin(); iter < myBook.end(); iter++) {
        out = out + "\n" + iter->toString();
    }
    return out;
}

int Player::getHandSize() const {           // returns size of hand as integer
    int size = 0;
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        size++;
    }
    return size;
}

int Player::getBookSize() const {
    int size = 0;
    for(vector <Card>::const_iterator iter = myBook.begin(); iter < myBook.end(); iter++) {
        size++;
    }
    return size;
}

bool Player::checkHandForPair(Card &c1, Card &c2) {
    vector <Card>::iterator iter1, iter2;
    for(iter1 = myHand.begin(); iter1 < myHand.end(); iter1++) {
        for(iter2 = myHand.begin(); iter2 < myHand.end(); iter2++) {
            c1 = *iter1;
            c2 = *iter2;
            return true;
        }
    }
    return false;
}

bool Player::sameRankInHand(Card c) const {
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if(iter->getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}
