#ifndef randy_h
#define randy_h

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
using std::string;

class Randy : public Character {

public:
    Randy();
    Card playCard();
    ~Randy();
};

#endif