//
// Created by Karl on 04.03.2021.
//

#ifndef INC_3CARDPOKER_CONSOLERENDERER_HPP
#define INC_3CARDPOKER_CONSOLERENDERER_HPP

#include <cstdint>

class consoleRenderer {

protected:
    void betsImplementation();

    void betAnteImplementation();
    void rebetAnteImplementation();

    void betPairPlusImplementation();
    void betSixCardImplementation();

    void currentChipsImplementation(int64_t chips);

private:
    void drawLine();

private:
    const uint8_t consoleLength = 30;
};


#endif //INC_3CARDPOKER_CONSOLERENDERER_HPP
