#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "deck.h"

class Player {
    int chips;
    std::vector<Card> hand;

    public:
        Player();
        int getChips();
        bool canAct();
        bool canPlay();
};

#endif
