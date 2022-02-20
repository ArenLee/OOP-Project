#include <iostream>
#include <limits>
#include "Card.h"
#include "Deck.h"

int main(){
    Deck playingDeck;
    int decksize = 10;
    playingDeck.generateDeck(decksize);

    if(playingDeck.max_size != decksize){ // generate error message if deck size not implemented correctly
        std::cout << "Error! Decksize doesn't match!" << std::endl;
    }

    for(int i=0; i<decksize; i++){
        // if the card's type is not rock, paper or scissors produce error message
        if(playingDeck.deckarray[i].gettype() != CardType::Paper && playingDeck.deckarray[i].gettype() != CardType::Rock && playingDeck.deckarray[i].gettype() != CardType::Scissors){
            std::cout << "Error! This card's type doesn't match any required." << std::endl;
        } else if(playingDeck.deckarray[i].getvalue() < 1 || playingDeck.deckarray[i].getvalue() > 9 || playingDeck.deckarray[i].getvalue()%1 != 0){ // if card's value is not valid produce error message
            std::cout << "Error! This card's value is not valid." << std::endl;
        }
    }
}
