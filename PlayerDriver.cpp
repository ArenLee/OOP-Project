#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Card.h"
#include "Deck.h"
#include "Character.h"
#include "Player.h"

int main(){
    // generate a deck for testing purposes
    Deck playingDeck;
    playingDeck.generateDeck(5);

    // generate the player class
    Player player1;
    player1.setname("You");

    // testing sethp() function with input validation
    int hp = 0;
    std::cout << "Please enter health points for both players (2 ~ 20): "; // prompt for user input
    for(;;) {
        if(std::cin >> hp && hp > 0 && std::cin.peek() == '\n'){ // if input is an int and is a number above 0
            break;
        } else{ // repeat the input until valid
            std::cout << "Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    player1.sethp(hp);
    std::cout << "Your total health points are: " << player1.gethp() << std::endl;

    // testing if drawcard function gives the correct card to players
    player1.drawcard(playingDeck.deckarray[0]);
    if(player1.hand[0].getvalue() != playingDeck.deckarray[0].getvalue()){
        std::cout << "Error! Card 1 drawn doesn't match card generated in deck!" << std::endl;
    }
    player1.drawcard(playingDeck.deckarray[4]);
    if(player1.hand[1].gettype() != playingDeck.deckarray[4].gettype()){
        std::cout << "Error! Card 2 drawn doesn't match card generated in deck!" << std::endl;
    }

    // testing if playcard function selects correct card and also its input validations
    player1.playCard();

    // check if card is removed from hand
    if(player1.hand.size() == 2){
        std::cout << "Error! Card was not removed from hand!" << std::endl;
    }
}