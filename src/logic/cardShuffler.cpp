//
// Created by Karl on 03.03.2021.
//

#include <iostream>
#include "cardShuffler.h"

hand cardShuffler::randomCards(size_t number) {
    hand result {};
    result.cType = static_cast<cardType>(m_rNum.randomNumber(static_cast<short>(cardType::BEGIN), static_cast<short>(cardType::END)));
    std::cout << (int)result.cType << std::endl;
    return result;
}

cardShuffler::cardShuffler() {}
