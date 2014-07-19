// Inclusion guard
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include "player.h"
#include "dealer.h"

class Blackjack
{
    Player player;
    Dealer dealer;
    public:
        Blackjack();
        Blackjack(int numplayers);
};

#endif
