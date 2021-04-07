//
// Created by Karl on 03.03.2021.
//

#ifndef INC_3CARDPOKER_CARDSHUFFLER_H
#define INC_3CARDPOKER_CARDSHUFFLER_H


#include <cstddef>
#include "hand.hpp"
#include "randomGenerator.hpp"

class cardShuffler {
private:
    randomGenerator<short> m_rNum;

public:
    cardShuffler();

    std::vector<hand> randomCards(size_t number = 1);
};


#endif //INC_3CARDPOKER_CARDSHUFFLER_H
