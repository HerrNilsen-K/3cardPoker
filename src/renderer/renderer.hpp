//
// Created by Karl on 04.03.2021.
//

#ifndef INC_3CARDPOKER_RENDERER_HPP
#define INC_3CARDPOKER_RENDERER_HPP


#include "consoleRenderer.hpp"

class renderer : protected consoleRenderer{

public:
    void bets();

    void betAnte();
    void rebetAnte();

    void betPairPlus();
    void betSixCard();

    void currentChips(int64_t chips);
};


#endif //INC_3CARDPOKER_RENDERER_HPP
