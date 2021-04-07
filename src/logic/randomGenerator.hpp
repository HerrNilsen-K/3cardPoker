//
// Created by Karl on 03.03.2021.
//

#ifndef INC_3CARDPOKER_RANDOMGENERATOR_HPP
#define INC_3CARDPOKER_RANDOMGENERATOR_HPP


#include <random>
#include <iostream>

template<class T>
class randomGenerator {
private:
    std::random_device m_rd;
    std::mt19937 m_mt {m_rd()};

public:
    randomGenerator()  {}

    T randomNumber(T min, T max) {
        std::uniform_int_distribution<T> result(static_cast<int64_t>(min), static_cast<int64_t>(max));
        return result(m_mt);
    }
};


#endif //INC_3CARDPOKER_RANDOMGENERATOR_HPP
