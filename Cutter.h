#ifndef cutter_h
#define cutter_h

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
using std::string;

class Cutter : public Character {

public:
    Cutter();
    Card playCard();
    ~Cutter();
};

#endif