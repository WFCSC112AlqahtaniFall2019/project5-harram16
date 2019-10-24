#include <iostream>
#include <math.h>

using namespace std;
#include "Deck.h"

//constructor class for Deck
Deck::Deck() {
    cout << "Constructor called." << endl;
    //setting the two private parameters in deck
    arraySize = 52;
    cardsLeft = 0;
    //creating array of 52 cards in Card
    cards = new Card[arraySize];

}

//copy constructor
Deck::Deck(const Deck &copyOfDeck) {
    cout << "Copy Constructor called." << endl;
    arraySize = copyOfDeck.arraySize;
    cardsLeft = copyOfDeck.cardsLeft;
    cards = new Card[arraySize];
    for (int i = 0; i < arraySize; i++) {
        cards[i] = copyOfDeck.cards[i];
    }
}

//destructor class for Deck
Deck::~Deck() {
    cout << "Destructor called." << endl;
    delete[] cards; //deletes array of cards
}

//copy assignment
Deck &Deck::operator=(Deck assignment) {
    cout << "Copy assignment called." << endl;
    swap(cards, assignment.cards);
    arraySize = assignment.arraySize;
    cardsLeft = assignment.cardsLeft;

    return *this;
}

//shuffle function
void Deck::shuffleDeck() {
    srand(time(0)); //creating a random "shuffle" every time

    for (int i = 0; i < pow(cardsLeft, 2); i++) {//number of times to shuffle deck
        swap(cards[rand() % 52], cards[rand() % 52]);
    }
}

//populate deck of cards
void Deck::populateDeck() {
    for (int i = 0; i < 4; i++) { //for each suit
        for (int j = 0; j < 13; j++) { //for each rank
            addCard(Card(j, i)); //populate each deck with a card of each rank and suit
        }
    }
}

//add cards to deck
bool Deck::addCard(Card newCard) {
    //checking to make sure deck is not full
    if (cardsLeft < arraySize) {
        cards[cardsLeft++] = newCard;//putting the card in the next spot in array of cards
        return true;
    }
    return false;
}

//remove cards from deck when drawn
Card Deck::removeCard() {
    return cards[-cardsLeft];
}