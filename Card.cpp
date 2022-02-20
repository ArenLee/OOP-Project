#include <iostream>
#include <random>
#include <string>
#include "Card.h"
using std::string;



Card::Card()
{
    std::random_device generator; // random number generator
    std::uniform_int_distribution<int> v_distribution(1,9); // random number between 1 amd 9 for the card's value
    std::uniform_int_distribution<int> t_distribution(1,3); // random number between 1 and 3 to be used in the switch cases
    value = v_distribution(generator);
    typevalue = t_distribution(generator);
    switch (typevalue) { // switch case to convert random number into the card's "type"
        case 1:
            type = CardType::Rock;
            printtype = "Rock";
            break;
        case 2:
            type = CardType::Paper;
            printtype = "Paper";
            break;
        case 3:
            type = CardType::Scissors;
            printtype = "Scissors";
            break;
    }
}

int Card::getvalue() // returns value of the card
{
    return value;
}

enum CardType Card::gettype() // returns card type
{
    return type;
}

string Card::getprinttype() // returns card type for printing purpose
{
    return printtype;
}

Card::~Card()
{
}