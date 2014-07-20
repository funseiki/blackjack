#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ctime> // for the random seed
#include <cstdlib>

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

        int getValue() {
            return value;
        }

        void print() {
            std::cout << name << " of " << suit << ": " << value << std::endl;
        }

};

class Deck
{
    /** Members that'll stay constant after constructor  **/
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
    Card standard_deck[52];

    /** Private members **/
    int num_standard_decks;
    std::vector<Card> current_deck;

    /** Private methods **/
    void fillStandardDeck();
    void buildDeck(int num_decks);

    public:
        Deck();
        int shuffle();
        Card drawCard();
        void printDeck();
        void addToDeck(std::vector<Card> v);
};

#endif
