//
// Created by Karl on 04.03.2021.
//

#include <iostream>
#include "consoleRenderer.hpp"

void consoleRenderer::betsImplementation() {
    std::cout << std::endl << "Please place your betsImplementation: " << std::endl;
    drawLine();
    std::cout << std::endl;
}

void consoleRenderer::drawLine() {
    for (int i = 0; i < consoleLength; ++i)
        std::cout << '-';
}

void consoleRenderer::betAnteImplementation() {
    std::cout << "Ante: ";
}

void consoleRenderer::betPairPlusImplementation() {
    std::cout << "Pair Plus: ";
}

void consoleRenderer::betSixCardImplementation() {
    std::cout << "Six Card: ";
}

void consoleRenderer::currentChipsImplementation(int64_t chips) {
    drawLine();
    std::cout << std::endl << "You currently have: " << chips << " chips" << std::endl;
}

void consoleRenderer::showPlayersCardsImplementation(std::vector<hand> &cards) {
    std::cout << "Your cards: ";
    for (auto &&i : cards) {
        std::tuple<std::string, short> card = getReadableHand(i);
        std::cout << std::get<1>(card) << " of " << std::get<0>(card) << ' ';
    }
    std::cout << std::endl;
}
