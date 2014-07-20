#include "player.h"

Player::Player()
{
    cout << "Hello player" << endl;
}

bool Player::canAct()
{
    return false;
}

bool Player::canPlay()
{
    return false;
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
