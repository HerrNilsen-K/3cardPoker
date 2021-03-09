//
// Created by Karl on 04.03.2021.
//

#include "renderer.hpp"

void renderer::betAnte() {
    betAnteImplementation();
}

void renderer::bets() {
    betsImplementation();
}

void renderer::betPairPlus() {
    betPairPlusImplementation();
}

void renderer::betSixCard() {
    betSixCardImplementation();
}

void renderer::currentChips(int64_t chips) {
    currentChipsImplementation(chips);
}

void renderer::showPlayersCards(std::array<hand, 3> &cards) {
    showPlayersCardsImplementation(cards);
}

void renderer::doesPlay() {
    doesPlayImplementation();
}

void renderer::showDealersCards(std::array<hand, 3> &cards) {
    showDealersCardsImplementation(cards);
}

void renderer::whoWon(bool playerWon) {
    whoWonImplementation(playerWon);
}
