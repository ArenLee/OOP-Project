#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
#include "Randy.h"
using std::string;

Randy::Randy()
{
    name = "Randy";
}

Card Randy::playCard()
{
    int selection = 0;
    std::random_device randomnumber; // random number generator
    std::uniform_int_distribution<int> randychoice(0,(hand.size()-1)); // random number between 0 and size of hand - 1
    selection = randychoice(randomnumber);

    // use input to return Card from hand
    Card choice; // placeholder for card selected
    choice = hand[selection];
    hand.erase(hand.begin()+(selection)); // remove the selected Card from the hand
    return choice; // return the card selected
}

Randy::~Randy()
{
}