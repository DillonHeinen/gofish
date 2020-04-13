#include "player.h"

using namespace std;

Player::Player() {
    myName = "Anonymous";
}

Player::Player(string name) {
    myName = name;
}

string Player::getName() const {
    return myName;
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {     // return to later
    vector <Card>::iterator iter1, iter2;

    for(iter1 = myHand.begin(); iter1 < myHand.end(); iter1++) {
        for(iter2 = myHand.begin(); iter2 < myHand.end(); iter2++) {
            if(iter1->sameSuitAs(*iter2)) {
                c1 = *iter1;
                c2 = *iter2;
                return true;
            }
        }
    }
    return false;
}

bool Player::rankInHand(Card c) const {
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if(iter->getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    unsigned int choice = rand() % myHand.size();
    return myHand.at(choice);
}

bool Player::cardInHand(Card c) const {
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if(*iter == c) {
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    Card yoink;
    for(vector <Card>::iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if(*iter == c) {
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
        out = out + "\n" + iter->toString();
    }
    return out;
}

string Player::showBooks() const {
    string out;
    for(vector <Card>::const_iterator iter = myBook.begin(); iter < myBook.end(); iter++) {
        out = out + "\n" + iter->toString();
    }
    return out;
}

int Player::getHandSize() const {
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

bool Player::checkHandForPair(Card &c1, Card &c2) {     // return to later
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

bool Player::sameRankInHand(Card c) const {     // return to later
    for(vector <Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++) {
        if(iter->getRank() == c.getRank()) {
            return true;
        }
    }
    return false;
}
