//
// Created by Karl on 03.03.2021.
//

#include <iostream>
#include <array>
#include "cardShuffler.h"

std::vector<hand> cardShuffler::randomCards(size_t number) {
    std::vector<hand> result(number);
    for (auto &&x : result) {
        x.cType = (cardType) m_rNum.randomNumber((short) cardType::BEGIN, (short) cardType::END);
        x.cValue = (cardValue) m_rNum.randomNumber((short) cardValue::BEGIN, (short) cardValue::END);
    }
    //std::cout << (short)result[0].cType << ' ' << (short)result[0].cValue << std::endl;
    return result;
}

cardShuffler::cardShuffler() {}
