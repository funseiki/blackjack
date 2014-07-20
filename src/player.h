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
    int chipsBet;
    string getInput();

    protected:
        vector<Card> hand;
    public:
        Player();
        Player(int startingChips):chips(startingChips), chipsBet(0) {}
        int getChips();
        bool canAct();
        bool canPlay();

        string getAction();
        int getBet();
        int getHandValue();
        void printState();
        void printHand();

        void addToHand(Card c);
};

#endif
