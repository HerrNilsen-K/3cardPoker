//
// Created by Karl on 03.03.2021.
//

#include "game.h"
#include "logic/cardShuffler.h"
#include "logic/hand.hpp"
#include "player/bankAccount.hpp"
#include "player/bets.hpp"
#include "renderer/renderer.hpp"
#include "input/input.hpp"

void game::run() {
    bool gameIsRrunning = true;
    cardShuffler cs;
    bankAccount playersBank;
    bets bet;
    renderer render;
    input in;


    while (gameIsRrunning) {
        //Take in the players betsImplementation
        render.betsImplementation();
        std::optional<int64_t> ante = {0}, pairPlus = {0}, sixCard = {0};
        render.betAnte();
        in.betAnte(ante);
        render.betPairPlus();
        in.betPairPlus(pairPlus);
        render.betSixCard();
        in.betSixCard(sixCard);

        std::vector<hand> dealer = cs.randomCards(3);
        std::vector<hand> player = cs.randomCards(3);

        gameIsRrunning = false;
    }
}
