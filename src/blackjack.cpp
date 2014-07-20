#include "blackjack.h"

Blackjack::Blackjack()
{
    std::cout << "Hello blackjack" << std::endl;
}

int Blackjack::startGame()
{
    // Initialize deck
    // Initialize players
    //  ^^ Happens in the constructor

    // The game loop
    do {
        // Shuffle deck
        deck.shuffle();

        // Collect bets from the player(s)
        getPlayerBets();

        // Deal out the cards
        dealCards();

        // Should probably make this a loop if there's gonna be more players
        if(getPlayerActions()) {
            getDealerActions();
        }

        // If player's won anything, hand over the chips
        distributeChips();
    } while(player.canPlay());

    return 1;
}

int Blackjack::getPlayerBets()
{
    gameText("Getting player bets");
    return 1;
}

void Blackjack::dealCards()
{
    gameText("Dealing cards");
}

int Blackjack::getPlayerActions()
{
    gameText("Getting player actions");
    return 1;
}

int Blackjack::parseAction()
{
    gameText("Parsing actions");
    return 1;
}


int Blackjack::getDealerActions()
{
    gameText("Getting dealer actions");
    return 1;
}

void Blackjack::distributeChips()
{
    gameText("Distributing chips");
}
