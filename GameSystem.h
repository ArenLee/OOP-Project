#ifndef game_h
#define game_h

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Character.h"
#include "Randy.h"
#include "Numbers.h"
using std::string;


class GameSystem {
public:
    GameSystem();
    void welcome(); // prints welcome message
    void charactersetup(); // initial setup of players
    void decksetup(); // initialize number of cards in deck
    void handsetup(); // starting hand setup
    void gamedisplay(); // display status screen (Name, HP)
    void choosecard(); // both players choose a card to play
    void resolvecombat(); // resolve the combat between cards chosen
    void dealdamage(); // calculate damage dealt
    void endturn(); // end the turn, progresses turn counter and draws card if possible
    void endgame(); // function for when game ends
    ~GameSystem();
    Deck gamedeck = {}; // variable to hold the deck used for the game
    Player P1 = {}; // variable for player 1, the user
    Character* P2 = {}; // variable for player 2, the computer
    Card P1Card = {}; // most recent card played by player 1
    Card P2Card = {}; // most recent card played by player 2
    int decksize = 0; // size of deck
    int turncount = 1; // turn counter
    int deckindex = 0; // variable used to keep track of cards in deck
    int damage = 0; // variable to hold damage dealt
    int result = 0; // variable to store combat result
};

#endif