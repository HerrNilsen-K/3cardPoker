//
// Created by Karl on 04.03.2021.
//

#ifndef INC_3CARDPOKER_CONSOLERENDERER_HPP
#define INC_3CARDPOKER_CONSOLERENDERER_HPP

#include <cstdint>

class consoleRenderer {

public:
    void betsImplementation();

    void betAnteImplementation();
    void betPairPlusImplementation();
    void betSixCardImplementation();

private:
    void drawLine();

private:
    const uint8_t consoleLength = 30;
};


#endif //INC_3CARDPOKER_CONSOLERENDERER_HPP
