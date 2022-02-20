#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
#include "Numbers.h"
using std::string;

Numbers::Numbers()
{
    name = "Numbers";
}

Card Numbers::playCard()
{
    int selection = 0; // variable to store the index of card selected
    Card choice = hand[0]; // variable to store card selected
    int largest = hand[0].getvalue(); // initialize variable to store largest card value as value of first card in hand

    // loop through to find the largest value card in hand to play
    for(int i=0; i<hand.size(); i++){
        if(hand[i].getvalue() > largest){
            largest = hand[i].getvalue();
            choice = hand[i];
            selection = i;
        }
    }

    hand.erase(hand.begin()+(selection)); // remove the selected Card from the hand
    return choice; // return the card selected
}

Numbers::~Numbers()
{
}