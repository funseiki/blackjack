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
    public:
        Blackjack();
        Blackjack(int numplayers);
};

#endif
