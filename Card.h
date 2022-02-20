#ifndef card_h
#define card_h

#include <iostream>
#include <string>
using std::string;

enum class CardType { Rock, Paper, Scissors }; // enum class declaration

class Card {
public:
    Card(); // cards will be randomly generated through default constructor
    int getvalue(); // returns card value
    CardType gettype(); // returns enum class type of card
    string getprinttype(); // returns card type
    ~Card();
    string printtype = {};
    CardType type = {};
    int typevalue = 0;
    int value = 0;
};

#endif