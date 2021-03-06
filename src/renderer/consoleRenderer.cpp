//
// Created by Karl on 04.03.2021.
//

#include <iostream>
#include "consoleRenderer.hpp"

void consoleRenderer::betsImplementation() {
    std::cout << std::endl << "Please place your bets: " << std::endl;
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

void consoleRenderer::showPlayersCardsImplementation(std::array<hand, 3> &cards) {
    std::cout << "Your cards: ";
    for (int j = 0; auto &&i : cards) {
        std::tuple<std::string, std::string> card = getReadableHand(i);
        std::cout << std::get<1>(card) << " of " << std::get<0>(card) << (j == cards.size() - 1 ? "." : ", ");
        ++j;
    }
    std::cout << std::endl;
}

void consoleRenderer::doesPlayImplementation() {
    std::cout << "Do you want to play? Y/N: ";
}

void consoleRenderer::showDealersCardsImplementation(std::array<hand, 3> &cards) {
    std::cout << "Dealers cards: ";
    for (int j = 0; auto &&i : cards) {
        std::tuple<std::string, std::string> card = getReadableHand(i);
        std::cout << std::get<1>(card) << " of " << std::get<0>(card) << (j == cards.size() - 1 ? "." : ", ");
        ++j;
    }
    std::cout << std::endl;
}

void consoleRenderer::whoWonImplementation(bool playerWon) {
    std::cout << "You have " << (playerWon ? "won" : "lost") << '.' << std::endl;
}

void consoleRenderer::antePayoutImplementation(int64_t anteProfit) {
    std::cout << "Your Ante Payout: " << anteProfit << std::endl;
}

void consoleRenderer::pairPlusPayoutImplementation(int64_t pairPlusProfit) {
    std::cout << "Your Pair Plus Payout: " << pairPlusProfit << std::endl;
}

void consoleRenderer::sixCardPayoutImplementation(int64_t sixCardProfit) {
    std::cout << "Your Six Card Payout: " << sixCardProfit << std::endl;
}
