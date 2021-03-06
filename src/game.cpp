//
// Created by Karl on 03.03.2021.
//

#include <array>
#include "game.h"
#include "logic/cardShuffler.h"
#include "logic/hand.hpp"
#include "player/bankAccount.hpp"
#include "player/bets.hpp"
#include "renderer/renderer.hpp"
#include "input/input.hpp"
#include "cards/cardsDeck.hpp"


void game::run() {
    bool gameIsRrunning = true;
    cardShuffler cs;
    bankAccount playersBank;
    bets bet;
    renderer render;
    input in;
    cardsDeck deck;


    while (gameIsRrunning) {
        //Take in the players betsImplementation
        render.currentChips(playersBank.getChips());
        render.bets();

        std::optional<int64_t> ante, pairPlus , sixCard;
        render.betAnte();
        in.betAnte(ante, playersBank);
        render.betPairPlus();
        in.betPairPlus(pairPlus, playersBank);
        render.betSixCard();
        in.betSixCard(sixCard, playersBank);

        //This need to be reworked
        std::vector<hand> dealer = cs.randomCards(3);
        std::vector<hand> player = cs.randomCards(3);

        render.showPlayersCards(player);



        gameIsRrunning = false;
    }
}
