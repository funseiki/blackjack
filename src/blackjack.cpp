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
        if(!getPlayerActions(player, "Player")) {
            stringstream s;
            s << "Player busts with " << player.getHandValue();
            gameText(s.str().c_str());
            // The player busted, we can just continue
            continue;
        }

        getPlayerActions(dealer, "Dealer");

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

bool Blackjack::getPlayerActions(Player& player, const char * name)
{
    std::stringstream s;
    s << "Getting " << name << " actions" << endl;
    gameText(s.str().c_str());
    while(player.canAct()) {
        s.str("");
        Action action = player.getAction();
        if(action.isHit()) {
            s << name << " has hit";
            gameText(s.str().c_str());
            player.addToHand(deck.drawCard());
        }
        else {
            s << name << " stands";
            gameText(s.str().c_str());
            break;
        }
    }
    player.printState();
    return player.getHandValue() <= 21;
}

void Blackjack::distributeChips()
{
    gameText("Distributing chips");
}
