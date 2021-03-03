//
// Created by Karl on 03.03.2021.
//

#include <iostream>
#include "cardShuffler.h"

hand cardShuffler::randomCards(size_t number) {
    hand result {};
    //result.cType = static_cast<cardType>(m_rNum.randomNumber(static_cast<short>(cardType::BEGIN), static_cast<short>(cardType::END)));
    result.cType = (cardType)m_rNum.randomNumber(0, 3);
    std::cout << (short)result.cType << std::endl;
    return result;
}

cardShuffler::cardShuffler() {}
