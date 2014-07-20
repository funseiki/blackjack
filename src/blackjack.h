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
    int getPlayerActions();
    int getDealerActions();
    void distributeChips();

    int parseAction();
    void dealCards();

    void gameText(const char * s) { std::cout << s << std::endl; }

    public:
        Blackjack();
        int startGame();
};

#endif
