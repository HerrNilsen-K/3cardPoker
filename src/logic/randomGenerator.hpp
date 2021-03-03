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
    std::mt19937 m_mt {m_rd()};

public:
    randomGenerator()  {}

    short randomNumber(T min, T max) {
        static std::uniform_int_distribution<short> result(static_cast<short>(min), static_cast<short>(max));
        return result(m_mt);
    }
};


#endif //INC_3CARDPOKER_RANDOMGENERATOR_HPP
