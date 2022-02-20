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
#include "Numbers.h"
#include "GameSystem.h"

int main(){

    GameSystem theboard;
    theboard.welcome();
    theboard.charactersetup();
    theboard.decksetup();
    theboard.handsetup();
    for(;;){
        theboard.gamedisplay();
        theboard.choosecard();
        theboard.resolvecombat();
        theboard.dealdamage();
        theboard.endturn();
        if(theboard.P1.gethp() < 1 || theboard.P2->gethp() < 1 || theboard.P1.hand.size() == 0){
            break;
        }
    }
    theboard.endgame();
}