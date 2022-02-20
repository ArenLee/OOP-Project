#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
#include "Cutter.h"
using std::string;

Cutter::Cutter()
{
    name = "Cutter";
}

Card Cutter::playCard()
{
    int selection = 0; // variable to store the index of card selected
    Card choice = {}; // variable to store card selected

    for(int i=0; i<hand.size(); i++){
        if(hand[i].gettype() == CardType::Scissors){ // picks the first scissors card he finds
            choice = hand[i];
            selection = i;
            break;
        }
    }

    if(choice.gettype() != CardType::Scissors){
        for(int i=0; i<hand.size(); i++){
            if(hand[i].gettype() == CardType::Paper){ // else picks the first paper card he finds
                choice = hand[i];
                selection = i;
                break;
            }else{ // otherwise picks rock
                choice = hand[i];
                selection = i;
            }
        }
    }

    hand.erase(hand.begin()+(selection)); // remove the selected Card from the hand
    return choice; // return the card selected
}

Cutter::~Cutter()
{
}