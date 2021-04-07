//
// Created by Karl on 06.03.2021.
//

#ifndef INC_3CARDPOKER_CARDSDECK_HPP
#define INC_3CARDPOKER_CARDSDECK_HPP


#include <queue>
#include "../logic/hand.hpp"

class cardsDeck {
private:

    //Hold information about the card and if it has already been drawn
    std::deque<hand> m_deck;
public:
    cardsDeck();

    void shuffleDeck();

    std::vector<hand> drawCards(int n);
};


#endif //INC_3CARDPOKER_CARDSDECK_HPP
