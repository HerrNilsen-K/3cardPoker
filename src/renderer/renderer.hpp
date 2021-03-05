//
// Created by Karl on 04.03.2021.
//

#ifndef INC_3CARDPOKER_RENDERER_HPP
#define INC_3CARDPOKER_RENDERER_HPP


#include "consoleRenderer.hpp"

class renderer : public consoleRenderer{

public:
    void bets();

    void betAnte();
    void betPairPlus();
    void betSixCard();
};


#endif //INC_3CARDPOKER_RENDERER_HPP
