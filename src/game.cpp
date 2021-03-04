//
// Created by Karl on 03.03.2021.
//

#include "game.h"
#include "logic/cardShuffler.h"
#include "logic/hand.hpp"
#include "player/bankAccount.hpp"
#include "player/bets.hpp"
#include "renderer/renderer.hpp"

void game::run() {
    bool gameIsRrunning = true;
    cardShuffler cs;
    bankAccount playersBank;
    bets bet;
    renderer render;

    while (gameIsRrunning) {
        render.bets();

        std::vector<hand> dealer = cs.randomCards(3);
        std::vector<hand> player = cs.randomCards(3);

        gameIsRrunning = false;
    }
}
