#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "deck.h"

// Gets really verbose if we need to std:: every input
using namespace std;

enum ActionType {
    STAND,
    HIT
};
class Action {
    ActionType t;
    public:
        Action(string s) {
            if(!s.compare("h") || !s.compare("hit")) {
                t = HIT;
            }
            else {
                t = STAND;
            }
        }
        ActionType getType() {
            return t;
        }
        bool isHit() {
            return t == HIT;
        }
        bool isStand() {
            return t == STAND;
        }
};

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

        Action getAction();
        int getBet();
        void resetBet();
        int getHandValue();
        void printState();
        void printHand();

        void addToHand(Card c);
        vector<Card> returnHand();
};

#endif
