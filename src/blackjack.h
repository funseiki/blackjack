// Inclusion guard
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <string>
#include "player.h"
#include "dealer.h"
#include "deck.h"

class Blackjack
{
    Player player;
    Dealer dealer;
    Deck deck;
    int getPlayerBets();
    bool getPlayerActions();
    int getDealerActions();
    void distributeChips();
    void initialize();

    void dealCards();

    void gameText(const char * s) {
        std::cout << "********************"<< std::endl;
        std::cout << s << std::endl;
        std::cout << "********************"<< std::endl;
        std::cin.ignore();
    }

    public:
        Blackjack();
        int startGame();
};

#endif
