//
// Created by karl on 05.03.21.
//

#include <iostream>
#include "consoleInput.hpp"
#include "../player/bankAccount.hpp"
#include "../renderer/renderer.hpp"

void consoleInput::betAnteImplementation(std::optional<int64_t> &ante, bankAccount &account) {
    ante.emplace();
    std::cin >> ante.value();
    m_ante = ante.value();
    if (account.getChips() > ante.value() * 2) {
        renderer render;

    }
}

void consoleInput::betPairPlusImplementation(std::optional<int64_t> &pairPlus, bankAccount &account) {
    pairPlus.emplace();
    std::cin >> pairPlus.value();
    m_pairPlus = pairPlus.value();
    if (account.getChips() < pairPlus.value() + m_ante) {

    }
}

void consoleInput::betSixCardImplementation(std::optional<int64_t> &sixCard, bankAccount &account) {
    sixCard.emplace();
    std::cin >> sixCard.value();
    m_sixCard = sixCard.value();
    if (account.getChips() < sixCard.value() + m_ante){

    }
}