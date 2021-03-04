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
    std::cout << (short)result[0].cType << ' ' << (short)result[0].cValue << std::endl;
    /*
    std::array<int, 4> count{};
    for (int i = 0; i < 4000; ++i) {
        result.cType = (cardType) m_rNum.randomNumber(0, 3);
        switch ((short) result.cType) {
            case 0:
                count[0]++;
                break;
            case 1:
                count[1]++;
                break;
            case 2:
                count[2]++;
                break;
            case 3:
                count[3]++;
                break;
        }
    }
    std::cout << "Count at 0: " << count[0] << std::endl;
    std::cout << "Count at 1: " << count[1] << std::endl;
    std::cout << "Count at 2: " << count[2] << std::endl;
    std::cout << "Count at 3: " << count[3] << std::endl << std::endl;
     */
    return result;
}

cardShuffler::cardShuffler() {}
