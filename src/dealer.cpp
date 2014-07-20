#include "dealer.h"

void Dealer::printPartial()
{
    cout << "Dealer's Hole Card" << endl;
    cout << "------------------" << endl;
    if(hand.size()) {
        hand.front().print();
    }
}

void Dealer::printState()
{

    cout << "Dealer State" << endl;
    cout << "------------" << endl;
    printHand();
    cout << endl << "-------------" << endl;
}

Action Dealer::getAction()
{
    printState();
    if(getHandValue() < 17) {
        return Action("hit");
    }
    else {
        return Action("stand");
    }

}
