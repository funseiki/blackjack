#include "player.h"

Player::Player()
{
    cout << "Hello player" << endl;
    chips = 100;
    chipsBet = 0;
}

bool Player::canAct()
{
    return false;
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

string Player::getAction()
{
    int attempts = 0;
    string in;
    while(attempts < 3) {
        cout << "Enter an action (h: hit, s: stand): ";
        in = getInput();
        if(!in.compare("h") || !in.compare("hit") || !in.compare("s") || !in.compare("stand")) {
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
    return in;
}

int Player::getBet()
{
    int attempts = 0;
    string in;
    int betAmount =  0;
    while(attempts < 3) {
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

void Player::printState()
{
    cout << "Player State" << endl;
    cout << "------------" << endl;
    cout << "Chips held: " << chips << endl;
    cout << "Chips bet: " << chipsBet << endl;
    cout << "Hand: ";
    for(vector<Card>::iterator it = hand.begin(); it != hand.end(); ++it) {
        it->print();
    }
    cout << endl << "-------------" << endl;
}
