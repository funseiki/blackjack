#include "deck.h"

Deck::Deck()
{
    int count = 0;
    for(int suit = 0; suit < 4; suit++)
    {
        for(auto it = card_value_mapping.begin(); it != card_value_mapping.end(); ++it)
        {
            cards[count].set(it->first, it->second, suit_map[suit]);
            count++;
        }
    }
}

void Deck::printDeck()
{
    for(int i = 0; i < 52; i++)
    {
        std::cout << cards[i].name << ", " << cards[i].value << "," << cards[i].suit << std::endl;
    }
}
