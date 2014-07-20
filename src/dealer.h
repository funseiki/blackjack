#ifndef DEALER_H
#define DEALER_H

#include "player.h"

class Dealer : public Player
{
    public:
        Dealer() : Player() { }
        Dealer(int startingChips):Player(startingChips) {}
        Action getAction();

        void printPartial();
        void printState();

};

#endif
