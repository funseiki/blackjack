// Inclusion guard
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include "player.h"
#include "dealer.h"
#include "deck.h"

class Blackjack
{
    Player player;
    Dealer dealer;
    Deck deck;
    int getPlayerActions();
    public:
        Blackjack();
        Blackjack(int numplayers);
        int startGame();
};

#endif
