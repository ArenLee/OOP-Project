#ifndef deck_h
#define deck_h

#include <iostream>
#include <string>
#include "Card.h"
using std::string;

class Deck {
public:
    Deck();
    void generateDeck(int size); // generate deck with specified number of cards
    void printDeck(); // for testing purposes
    ~Deck();
    Card* deckarray;
    int max_size = 0;
};

#endif