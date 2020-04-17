#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "deck.h"
#include "player.h"

using namespace std;

int main() {

    ofstream oFile;
    oFile.open("test.txt");
    oFile << "Go Fish!" << endl;
    oFile << endl;

    const int numCards = 7;              // 7 cards to be dealt for two players

    Deck d;
    d.shuffle();

    Card c1;    // pair of cards to temporarily hold books
    Card c2;

    Player p1("Dillon");    // instantiation of players
    Player p2("Laurel");

    for(int i = 0; i < numCards; i++) {     // deals shuffled deck to players
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }

//    cout << p1.getName() << "'s hand is: " << p1.showHand() << endl;       // Check hand for debugging
//    cout << p2.getName() << "'s hand is: " << p2.showHand() << endl;

//    cout << endl;

    while(p1.checkHandForBook(c1, c2)) {       // initial booking of cards for p1
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
        oFile << p1.getName() << " books " << c1.getRank() << endl;
    }
    while(p2.checkHandForBook(c1, c2)) {        // initial booking of cards for p2
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
        oFile << p2.getName() << " books " << c2.getRank() << endl;
    }
    oFile << endl;

    while((d.size() != 0) || ((p1.getHandSize() != 0) || (p2.getHandSize() != 0))) {
//        cout << endl;
//        cout << endl;
//        cout << "Dillon is " << p1.showHand() << endl;
//        cout << "Laurel is " << p2.showHand() << endl;
//        cout << endl;

        if(p1.getHandSize() != 0) {                                     // player 1's turn
            Card temp = p1.chooseCardFromHand();
            oFile << p1.getName() << " asks - Do you have a " << c1.rankString(temp.getRank()) << "?" << endl;

            if (p2.rankInHand(temp)) {
                oFile << p2.getName() << " says - Yes. I have a " << c1.rankString(temp.getRank()) << "." << endl;
                p1.addCard(p2.removeCardFromHand(temp));
            } else {
                oFile << p2.getName() << " says - Go Fish." << endl;
                if (d.size() != 0) {            // deal card for go fish
                    Card deal = d.dealCard();
                    p1.addCard(deal);
                    oFile << p1.getName() << " draws " << deal.toString() << endl;
                }
            }
        }
        while(p1.checkHandForBook(c1, c2)) {       // booking of cards for p1
            p1.bookCards(c1, c2);
            p1.removeCardFromHand(c1);
            p1.removeCardFromHand(c2);
            oFile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
        }
        if((d.size() != 0) && (p1.getHandSize() == 0)) {
            p1.addCard(d.dealCard());
        }

        oFile << endl;

        if(p2.getHandSize() != 0) {                                     // player 2's turn
            Card temp = p2.chooseCardFromHand();
            oFile << p2.getName() << " asks - Do you have a " << c2.rankString(temp.getRank()) << "?" << endl;

            if (p1.rankInHand(temp)) {
                oFile << p1.getName() << " says - Yes. I have a " << c2.rankString(temp.getRank()) << "." << endl;
                p2.addCard(p1.removeCardFromHand(temp));
            } else {
                oFile << p1.getName() << " says - Go Fish." << endl;
                if (d.size() != 0) {
                    Card deal = d.dealCard();
                    p2.addCard(deal);
                    oFile << p2.getName() << " draws " << deal.toString() << endl;
                }
            }
        }
        while(p2.checkHandForBook(c1, c2)) {        // booking of cards for p2
            p2.bookCards(c1, c2);
            p2.removeCardFromHand(c1);
            p2.removeCardFromHand(c2);
            oFile << p2.getName() << " books the " << c2.rankString(c2.getRank()) << endl;
        }
        if((d.size() != 0) && (p2.getHandSize() == 0)) {
            p2.addCard(d.dealCard());
        }
        oFile << endl;

        if(p1.getBookSize() > p2.getBookSize()) {
            oFile << p1.getName() << " has more books and wins the game!" << endl;
        }
        else {
            oFile << p2.getName() << " has more books and wins the game!" << endl;
        }
    }
    oFile << "Thus concludes Go Fish!" << endl;
//    cout << p1.showBooks() << endl;
//    cout << p2.showBooks() << endl;

    oFile.close();

    return EXIT_SUCCESS;
}
