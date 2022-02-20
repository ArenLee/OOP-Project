#ifndef character_h
#define character_h

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
using std::string;

class Character {

public:
    virtual Card playCard() = 0; // virtual function since each player will have different styles
    void setname(string); // function to set name
    string getname(); // funciton to return name
    void sethp(int); // function to set hitpoints
    int gethp(); // function to return hitpoints
    void drawcard(Card); // functions to draw card (add a Card to the hand vector)
    std::vector<Card> hand; // initializing a vector to holds Cards
    void showHand(); // function to list cards currently in hand
    string name = {};
    int hitpoints = 0;
    virtual ~Character();

};

#endif