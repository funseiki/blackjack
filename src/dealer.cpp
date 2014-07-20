#include "dealer.h"

void Dealer::printPartial()
{
    cout << "Dealer's Hole Card" << endl;
    cout << "------------------" << endl;
    if(hand.size()) {
        hand.front().print();
    }
}
