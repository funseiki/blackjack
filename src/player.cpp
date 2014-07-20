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

int Player::getHandValue()
{
    int value = 0;
    for(vector<Card>::iterator it = hand.begin(); it != hand.end(); ++it) {
        value += it->getValue();
    }
    return value;
}

void Player::addToHand(Card c)
{
    hand.push_back(c);
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
