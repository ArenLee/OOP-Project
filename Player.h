#ifndef player_h
#define player_h

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
using std::string;

class Player : public Character {

public:
    Player();
    Card playCard(); // player's function to play card
    ~Player();
};

#endif