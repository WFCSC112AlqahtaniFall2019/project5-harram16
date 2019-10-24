#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    Deck();

    Deck(const Deck &copy);

    ~Deck();

    Deck &operator=(Deck assignment);

    void shuffleDeck();

    void populateDeck();

    Card removeCard();

    bool addCard(Card newCard);

private:
    Card *cards; //(pointer to array of cards)
    int arraySize; //(physical size of array)
    int cardsLeft; //(logical size of array)

};


#endif //BLINDMANSBLUFF_DECK_H
