#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <unordered_map>

// Keeping all three class/enum declarations here since they're small and related

class Card
{
    public:
        int value;
        std::string name;
        std::string suit;

        Card() { }
        Card(std::string card_name, int val, std::string card_suit) {
            value = val;
            name = card_name;
            suit = card_suit;
        }
        void set(std::string card_name, int val, std::string card_suit) {
            value = val;
            name = card_name;
            suit = card_suit;
        }

};

class Deck
{
    std::string suit_map[4] = {"SPADE", "DIAMOND", "HEART", "CLUB"};
    // Totally unnecessary to use this, but wanted to try it out
    std::unordered_map<std::string, int> card_value_mapping = {
        {"Ace", 11}, // Will need to check for this special case
        {"King", 10},
        {"Queen", 10},
        {"Jack", 10},
        {"Ten", 10},
        {"Nine", 9},
        {"Eight", 8},
        {"Seven", 7},
        {"Six", 6},
        {"Five", 5},
        {"Four", 4},
        {"Three", 3},
        {"Two", 2}
    };

    Card cards[52];
    public:
        Deck();
        int shuffle();
        Card drawCard();
        void printDeck();
};

#endif
