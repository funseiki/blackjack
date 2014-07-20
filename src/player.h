#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "deck.h"

// Gets really verbose if we need to std:: every input
using namespace std;

class Player {
    int chips;
    vector<Card> hand;
    string getInput();

    public:
        Player();
        int getChips();
        bool canAct();
        bool canPlay();

        string getAction();
        int getBet();
};

#endif
