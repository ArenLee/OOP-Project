#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
using std::string;

void Character::setname(string yourname)
{
    name = yourname;
}

string Character::getname()
{
    return name;
}

void Character::sethp(int health)
{
    hitpoints = health;
}

int Character::gethp()
{
    return hitpoints;
}

void Character::drawcard(Card drawncard)
{
    hand.push_back (drawncard);
}

void Character::showHand()
{
    for(int i=0; i<hand.size(); i++){
        std::cout << "[" << i+1 << "] " << hand[i].getprinttype() << ":" << hand[i].getvalue() << "\t\t";
    }

    std::cout << std::endl;
}