#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
using std::string;

Deck::Deck()
{
    deckarray = new Card [0];
    max_size = 0;
}

void Deck::generateDeck(int size) // generate a deck of Cards
{
    deckarray = new Card [size]; // creates dynamic array of Cards based on the input
    max_size = size;
    for(int i=0; i< max_size; i++){
        deckarray[i] = Card(); // creates a card for each element of this dynamic array
    }
}

void Deck::printDeck() // function for testing purposes, for checking if card drawn equals to card in deck
{
    for(int i=0; i<max_size; i++){
        std::cout << "Card value: " << deckarray[i].getvalue() << ", Card type: " << deckarray[i].getprinttype() << std::endl;
    }
}

Deck::~Deck()
{
    delete[] deckarray; // frees the memory used for the dyanamic array
}