#include "Card.h"

//constructor
Card::Card() {

}

//constructor
Card::Card(int r, int s) {
    mySuit = s;
    myRank = r;
}

//overload operator
bool Card::operator>(Card computer) {
    if (myRank != computer.myRank) {
        return myRank > computer.myRank;
    } else {
        return mySuit > computer.mySuit;
    }
}


string Card::CardToString() { //returns the string of Rank and Suit
    return ranks[myRank] + " of " + suits[mySuit];
}

