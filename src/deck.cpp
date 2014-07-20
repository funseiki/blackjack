#include "deck.h"

Deck::Deck()
{
    // As per http://www.cplusplus.com/reference/algorithm/random_shuffle/
    std::srand( unsigned(std::time(0)) );

    num_standard_decks = 1;
    fillStandardDeck();
    buildDeck(num_standard_decks);
}

void Deck::fillStandardDeck()
{
    int count = 0;
    for(int suit = 0; suit < 4; suit++)
    {
        for(auto it = card_value_mapping.begin(); it != card_value_mapping.end(); ++it)
        {
            standard_deck[count].set(it->first, it->second, suit_map[suit]);
            count++;
        }
    }
}

void Deck::buildDeck(int num_decks)
{
    for(int i = 0; i < num_decks; i++)
    {
        for(int j = 0; j < 52; j++)
        {
            current_deck.push_back(standard_deck[j]);
        }
    }
}

int Deck::shuffle()
{
    std::random_shuffle( current_deck.begin(), current_deck.end() );
    return 0;
}

Card Deck::drawCard()
{
    Card ret = current_deck.back();
    current_deck.pop_back();
    return ret;
}

void Deck::printDeck()
{
    for(std::vector<Card>::iterator it = current_deck.begin(); it != current_deck.end(); ++it)
    {
        std::cout << it->name << " of " << it->suit << ": " << it->value << std::endl;
    }
}
