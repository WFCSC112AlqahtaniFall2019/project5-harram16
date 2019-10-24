#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int compValue, userValue, nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));

    //creating two decks the original and the discard
    Deck playingDeck;
    Deck discardDeck;

    //populating the deck with cards then shuffling
    playingDeck.populateDeck();
    playingDeck.shuffleDeck();

    //testing calling copy constructor and copy assignment
    Deck copyDeck;
    copyDeck = playingDeck;
    //Card testPlayingDeck;
    //Card testCopyDeck;



    play = true;
    while(play) {
        // assign cards to computer and user and put them in discard deck to keep track of number of cards played
        Card user = playingDeck.removeCard();
        Card computer = playingDeck.removeCard();
        discardDeck.addCard(user);
        discardDeck.addCard(computer);
        //checking to make sure you have not run out of cards by seeing if you can add to discard pile
        if (discardDeck.addCard(computer) == false) {
            cout << "You have used all of the cards in the deck. Game Over." << endl;
            break;
        }

        // get user's bet
        cout << "Computer's value is " << computer.CardToString() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if ((user > computer && guessedHigher) || (computer > user && !guessedHigher)) {
            cout << "Great! You're right:" << " your card was " << user.CardToString() << endl;
            nWin++;
        } else if ((computer > user && guessedHigher) || (user > computer && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << " your card was " << user.CardToString() << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << userValue << endl;

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }


        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}