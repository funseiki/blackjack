#include "blackjack.h"

Blackjack::Blackjack()
{
    std::cout << "Hello blackjack" << std::endl;
}

void Blackjack::initialize()
{
    deck.addToDeck(player.returnHand());
    deck.addToDeck(dealer.returnHand());
    player.reset();
    dealer.reset();
}

int Blackjack::startGame()
{
    // Initialize deck
    // Initialize players
    //  ^^ Happens in the constructor

    // The game loop
    do {
        // return hands and set bets to 0
        initialize();

        // Shuffle deck
        deck.shuffle();

        // Collect bets from the player(s)
        getPlayerBets();

        // Deal out the cards
        dealCards();

        // Should probably make this a loop if there's gonna be more players
        if(!getPlayerActions()) {
            stringstream s;
            s << "Player busts with " << player.getHandValue();
            gameText(s.str().c_str());
            // The player busted, we can just continue
            continue;
        }

        getDealerActions();

        // If player's won anything, hand over the chips
        distributeChips();
    } while(player.canPlay());

    std::cout << "Game over" << std::endl;
    return 1;
}

int Blackjack::getPlayerBets()
{
    gameText("Getting player bets");
    player.getBet();
    return 1;
}

void Blackjack::dealCards()
{
    gameText("Dealing cards");
    // Could perhaps use a loop for this
    player.addToHand(deck.drawCard());
    dealer.addToHand(deck.drawCard());
    player.addToHand(deck.drawCard());
    dealer.addToHand(deck.drawCard());
    dealer.printPartial();
}

bool Blackjack::getPlayerActions()
{
    gameText("Getting player actions");
    while(player.canAct()) {
        Action action = player.getAction();
        if(action.isHit()) {
            gameText("Player has hit");
            player.addToHand(deck.drawCard());
        }
        else {
            gameText("Player stands");
            break;
        }
    }
    return player.getHandValue() < 21;
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
