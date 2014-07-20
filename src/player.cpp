#include "player.h"

Player::Player()
{
    cout << "Hello player" << endl;
    chips = 100;
    reset();
}

bool Player::canAct()
{
    return getHandValue() < 21;
}

bool Player::canPlay()
{
    return chips > 0;
}

string Player::getInput()
{
    string ret;
    getline(cin, ret);
    return ret;
}

Action Player::getAction()
{
    int attempts = 0;
    string in;
    while(attempts < 3) {
        printState();
        cout << "Enter an action (h: hit, s: stand): ";
        in = getInput();
        if(!in.compare("h") || !in.compare("hit") || !in.compare("s") || !in.compare("stand")) {
            break;
        }
        else {
            cout << "Incorrect input, attempt " << ++attempts << endl;
        }
    }
    printState();

    // Too many bad inputs
    if(attempts > 2) {
        cout << "Too many failed attempts. Exiting game" << endl;
        exit(1);
    }
    return Action(in);
}

int Player::getBet()
{
    int attempts = 0;
    string in;
    int betAmount =  0;
    while(attempts < 3) {
        printState();
        cout << "Enter bet amount: ";
        in = getInput();
        if(stringstream(in) >> betAmount && betAmount <= chips &&  betAmount > 0) {
            break;
        }
        else {
            cout << "Incorrect input, attempt " << ++attempts << endl;
        }
    }

    // Too many bad inputs
    if(attempts > 2) {
        cout << "Too many failed attempts. Exiting game" << endl;
        exit(1);
    }

    chipsBet = betAmount;
    chips -= chipsBet;

    printState();
    return betAmount;
}

// Returns highest possible value under 21
int Player::getHandValue()
{
    int value = 0;
    value += nonAceTotal;
    // The below can probably just be put into addtohand, so it's only done once
    if(numAces > 0) {
        // If we have more than one ace, all except one MUST act as 1 instead of 11
        value += (numAces - 1);

        if(value <= 10) {
            value += 11;
        }
        else {
            value += 1;
        }
    }
    return value;
}

void Player::addToHand(Card c)
{
    hand.push_back(c);
    if(c.value != 11) {
        nonAceTotal += c.value;
    }
    else {
        numAces++;
    }
}

vector<Card> Player::returnHand()
{
    vector<Card> oldHand;
    unsigned int length = hand.size();
    for(unsigned int i = 0; i < length; i++) {
        oldHand.push_back(hand.back());
        hand.pop_back();
    }
    return oldHand;
}

void Player::reset()
{
    chipsBet = 0;
    numAces = 0;
    nonAceTotal = 0;
}

void Player::printState()
{
    cout << "Player State" << endl;
    cout << "------------" << endl;
    cout << "Chips held: " << chips << endl;
    cout << "Chips bet: " << chipsBet << endl;
    printHand();
    cout << endl << "-------------" << endl;
}

void Player::printHand()
{
    cout << "Hand: [";
    for(vector<Card>::iterator it = hand.begin(); it != hand.end(); ++it) {
        it->print();
        cout << ", ";
    }
    cout << "]" << endl;;
    cout << "Hand Total: " << getHandValue() << endl;
}
