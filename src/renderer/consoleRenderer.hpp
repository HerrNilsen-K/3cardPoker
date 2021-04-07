//
// Created by Karl on 04.03.2021.
//

#ifndef INC_3CARDPOKER_CONSOLERENDERER_HPP
#define INC_3CARDPOKER_CONSOLERENDERER_HPP

#include <cstdint>
#include <vector>
#include "../logic/hand.hpp"

class consoleRenderer {

protected:
    void betsImplementation();

    void betAnteImplementation();

    void betPairPlusImplementation();
    void betSixCardImplementation();

    void currentChipsImplementation(int64_t chips);

    void showPlayersCardsImplementation(std::array<hand, 3> &cards);
    void showDealersCardsImplementation(std::array<hand, 3> &cards);

    void doesPlayImplementation();

    void whoWonImplementation(bool playerWon);


    void antePayoutImplementation(int64_t anteProfit);
    void pairPlusPayoutImplementation(int64_t pairPlusProfit);
    void sixCardPayoutImplementation(int64_t sixCardProfit);

private:
    void drawLine();

private:
    const uint8_t consoleLength = 30;
};


#endif //INC_3CARDPOKER_CONSOLERENDERER_HPP
