//
// Created by Karl on 03.03.2021.
//

#include "game.h"
#include "logic/cardShuffler.h"
#include "logic/hand.hpp"

void game::run() {
    bool gameIsRrunning = true;
    cardShuffler cs;
    while (gameIsRrunning){
        hand dealer = cs.randomCards(3);
        hand player = cs.randomCards(3);

        gameIsRrunning = false;
    }
}
