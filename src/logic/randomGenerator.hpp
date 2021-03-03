//
// Created by Karl on 03.03.2021.
//

#ifndef INC_3CARDPOKER_RANDOMGENERATOR_HPP
#define INC_3CARDPOKER_RANDOMGENERATOR_HPP


#include <random>

template<class T>
class randomGenerator {
private:
    std::random_device m_rd;
    std::mt19937 m_mt;

public:
    randomGenerator() : m_mt(m_rd()) {}

    T randomNumber(T min, T max) {
        return std::uniform_int_distribution<T>{static_cast<size_t >(min), static_cast<size_t >(max)}(m_mt);
    }
};


#endif //INC_3CARDPOKER_RANDOMGENERATOR_HPP
