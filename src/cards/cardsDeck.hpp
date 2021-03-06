//
// Created by Karl on 06.03.2021.
//

#ifndef INC_3CARDPOKER_CARDSDECK_HPP
#define INC_3CARDPOKER_CARDSDECK_HPP


#include <array>
#include "../logic/hand.hpp"

class cardsDeck {
private:
    std::array<hand, 52> m_deck;
};


#endif //INC_3CARDPOKER_CARDSDECK_HPP
