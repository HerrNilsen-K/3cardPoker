//
// Created by Karl on 04.03.2021.
//

#ifndef INC_3CARDPOKER_RENDERER_HPP
#define INC_3CARDPOKER_RENDERER_HPP


#include <vector>
#include "consoleRenderer.hpp"
#include "../logic/hand.hpp"

class renderer : protected consoleRenderer {

public:
    void bets();

    void betAnte();

    void betPairPlus();

    void betSixCard();

    void currentChips(int64_t chips);

    void showPlayersCards(std::array<hand, 3> &cards);

    void doesPlay();

    void showDealersCards(std::array<hand, 3> &cards);
};


#endif //INC_3CARDPOKER_RENDERER_HPP
