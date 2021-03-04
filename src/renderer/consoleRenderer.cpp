//
// Created by Karl on 04.03.2021.
//

#include <iostream>
#include "consoleRenderer.hpp"

void consoleRenderer::bets() {
    drawLine();
    std::cout << std::endl << "Please place your bets: " << std::endl;
    drawLine();
}

void consoleRenderer::drawLine() {
    for(int i = 0; i < consoleLength; ++i)
        std::cout << '-';
}
