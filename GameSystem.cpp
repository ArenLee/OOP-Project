#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Character.h"
#include "Randy.h"
#include "Cutter.h"
#include "GameSystem.h"
using std::string;


GameSystem::GameSystem()
{
}

void GameSystem::welcome()  // prints welcome message and game rules
{
    std::cout << "----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Welcome to Roshambo Battle! Please have a quick look over the rules: " << std::endl;
    std::cout << "1. Pick a card to play, each card will be represented by Rock,Paper or Scissors along with a value.\n" <<
    "2. Standard Rock,Paper,Scissors rules apply: Rock beats Scissors, Scissors beats Paper, Paper beats Rock.\n" <<
    "3. The losing player takes damage equal to the difference between the winner's card and the loser's card.\n" <<
    "4. But wait! Negative damage will heal the losing player, and damage greater than 5 will be reflected back to the winner.\n" <<
    "5. Game continues until a player's hit points reaches 0, or when both sides run out of cards to play, in which the player with the higher hit points win!" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}


void GameSystem::charactersetup()  // function to setup both players of the game (user name, opponenet selection, and hitpoints input)
{
    // initialize player
    string yourname = {};
    std::cout << "Please enter player name: ";
    std::cin >> yourname;
    P1.setname(yourname);

    // initialize opponent
    string oppo = {};
    std::cout << "Please select an opponent (Randy/Cutter/Numbers): ";
    // based on input, select opponent
    for(;;) {
        std::cin >> oppo;
        if(oppo == "Randy" || oppo == "randy"){
            P2 = new Randy;
            break;
        } else if(oppo == "Cutter" || oppo == "cutter"){
            P2 = new Cutter;
            break;
        } else if(oppo == "Numbers" || oppo == "numbers"){
            P2 = new Numbers;
            break;
        } else{
            std::cout << "Error! Please enter a correct name: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // initialize player's hitpoints
    int hp = 0;
    std::cout << "Please enter health points for both players (5 ~ 10): "; // prompt for user input
    for(;;) {
        if(std::cin >> hp && hp > 0 && std::cin.peek() == '\n'){ // if input is an int and is a number above 0
            break;
        } else{ // repeat the input until valid
            std::cout << "Error! Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    P1.sethp(hp);
    P2->sethp(hp);
}


void GameSystem::decksetup()
{
    // input deck size
    std::cout << "Please enter number of cards in deck (10 ~ 20): "; // prompt for user input
    // infinite for loop for input validation
    for(;;) {
        if(std::cin >> decksize && decksize > 0 && decksize%2 == 0 && std::cin.peek() == '\n'){ // if input is an int and is an even number above 0
            break;
        } else{ // repeat the input until valid
            std::cout << "Error! Please enter an even number for the deck: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // generate actual deck of cards
    gamedeck.generateDeck(decksize);
}

void GameSystem::handsetup()
{
    // deal out initial hand of cards
    std::cout << "Dealing cards..." << std::endl;
    for(int i = 0; i<5; i++){ // starting hand size of 5 maximum
        if(deckindex >= decksize-1){
            break;
        } else{
            P1.drawcard(gamedeck.deckarray[deckindex]);
            deckindex++;
            P2->drawcard(gamedeck.deckarray[deckindex]);
            deckindex++;
        }
    }

    std::cout << "----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}


void GameSystem::gamedisplay()
{
    // show character names and health points
    std::cout << "Turn: " << turncount << std::endl;
    std::cout << std::left << std::setw(70) << P1.getname() << std::right << P2->getname() << "\n";
    std::cout << "HP: "  << std::left << std::setw(66) << P1.gethp() << std::right << "HP: " << P2->gethp() << std::endl;
    std::cout << std::endl;
}


void GameSystem::choosecard()
{
    // player 1 chooses a card to play
    std::cout << "Your hand: " << std::endl;
    P1.showHand();
    P1Card = P1.playCard();
    std::cout << std::endl;

    // player 2 chooses card to play
    P2Card = {}; // reset card choice
    P2Card = P2->playCard();

    // display card played
    std::cout << "You played: \t\t" << P1Card.getprinttype() << " with strength of " << P1Card.getvalue() << std::endl;
    std::cout << "Opponent played: \t" << P2Card.getprinttype() << " with strength of " << P2Card.getvalue() << std::endl;
    std::cout << std::endl;
}


void GameSystem::resolvecombat()
{
    // re-initialize variable for damage dealt and matchup result
    result = 0;

    // resolve the card type matchups
    if(P1Card.gettype() == CardType::Rock && P2Card.gettype() == CardType::Paper){
        result = 1;
    } else if(P1Card.gettype() == CardType::Rock && P2Card.gettype() == CardType::Scissors){
        result = 2;
    } else if(P1Card.gettype() == CardType::Scissors && P2Card.gettype() == CardType::Rock){
        result = 1;
    } else if(P1Card.gettype() == CardType::Scissors && P2Card.gettype() == CardType::Paper){
        result = 2;
    } else if(P1Card.gettype() == CardType::Paper && P2Card.gettype() == CardType::Scissors){
        result = 1;
    } else if(P1Card.gettype() == CardType::Paper && P2Card.gettype() == CardType::Rock){
        result = 2;
    } else if(P1Card.gettype() == P2Card.gettype()){
        result = 3;
    }
}


void GameSystem::dealdamage()
{
    // re-initialize damage variable
    damage = 0;

    // resolve damage dealt
    switch(result){
        case 1 :
        damage = P2Card.getvalue()-P1Card.getvalue();
        if(damage > 5){
            P2->hitpoints = P2->hitpoints - damage;
            std::cout << "Damage reflected! Opponent takes " << damage << " damage." << std::endl;
        } else if(damage < 0) {
            P1.hitpoints = P1.hitpoints - damage;
            std::cout << "Lost the battle but won the war! You heal " << -damage << " health." << std::endl;
        } else {
            P1.hitpoints = P1.hitpoints - damage;
            std::cout << "Lost the fight! You take " << damage << " damage." << std::endl;
        } break;

        case 2 :
        damage = P1Card.getvalue()-P2Card.getvalue();
        if(damage > 5){
            P1.hitpoints = P1.hitpoints - damage;
            std::cout << "You were too strong! Damage reflected and you take " << damage << " damage." << std::endl;
        } else if(damage < 0) {
            P2->hitpoints = P2->hitpoints - damage;
            std::cout << "Won the battle but lost the war! Opponent heals " << -damage << " health." << std::endl;
        } else {
            P2->hitpoints = P2->hitpoints - damage;
            std::cout << "Won the fight! Opponent takes " << damage << " damage." << std::endl;
        } break;

        case 3 :
        std::cout << "It was a draw!" << std::endl;
        break;

        default :
        std::cout << "It seems there was an error, result was not defined" << std::endl;
    }
}


void GameSystem::endturn()
{
    // both players draw a card if possible
    if(deckindex < decksize-1){
        P1.drawcard(gamedeck.deckarray[deckindex]);
        deckindex++;
        P2->drawcard(gamedeck.deckarray[deckindex]);
        deckindex++;
    }

    // turn counter increase
    turncount++;

    // print turn separator
    std::cout << "----------------------------------------------------------------------------------------------------------------------------------" << std::endl;
}


void GameSystem::endgame()
{
    std::cout << std::endl;

    if(P1.gethp() == 0){
        std::cout << "You lose!" << std::endl;
    } else if(P2->gethp() == 0){
        std::cout << "You win!" << std::endl;
    } else if(P1.hand.size() == 0 && P1.gethp() > P2->gethp()){
        std::cout << "No more cards! As the player with the higher hitpoints, you win!" << std::endl;
    } else if(P1.hand.size() == 0 && P1.gethp() < P2->gethp()){
        std::cout << "No more cards! As the player with the lower hitpoints, you lose!" << std::endl;
    }
}


GameSystem::~GameSystem()
{
}