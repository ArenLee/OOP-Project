#ifndef numbers_h
#define numbers_h

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
using std::string;

class Numbers : public Character {

public:
    Numbers();
    Card playCard();
    ~Numbers();
};

#endif