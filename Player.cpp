#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
#include "Player.h"
using std::string;

Player::Player()
{
}

Card Player::playCard()
{
    // initialize variable for input
    int cardpos = 0;
    std::cout << "Which card would you like to play? "; // prompt for user choice
    // infinite for loop for input validation
    for(;;) {
        if(std::cin >> cardpos && cardpos >= 1 && cardpos <= hand.size() && std::cin.peek() == '\n'){ // if input is a card within the hand
            std::cout << std::endl;
            break;
        } else{ // repeat the input until valid
            std::cout << "Please choose a card from your hand: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // use input to return chosen Card from hand
    Card choice; // placeholder for card selected
    choice = hand[cardpos-1];
    hand.erase(hand.begin()+(cardpos-1)); // remove the selected Card from the hand
    return choice; // return the card selected
}

Player::~Player()
{
}