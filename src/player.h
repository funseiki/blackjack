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
        int nonAceTotal;
        int numAces;
    public:
        Player();
        Player(int startingChips):chips(startingChips), chipsBet(0),
                nonAceTotal(0), numAces(0) {}
        int getChips() { return chips; }
        int getChipsBet(){ return chipsBet; }

        bool canAct();
        bool canPlay();

        int getBet();
        void reset();
        int getHandValue();
        void printHand();

        void addChips(int chipCount);
        void addToHand(Card c);
        vector<Card> returnHand();

        /** Virtual Methods **/
        virtual Action getAction();
        virtual void printState();

};

#endif
