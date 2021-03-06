//
// Created by karl on 05.03.21.
//

#include <iostream>
#include "consoleInput.hpp"
#include "../player/bankAccount.hpp"
#include "../renderer/renderer.hpp"

void consoleInput::betAnteImplementation(std::optional<int64_t> &ante, bankAccount &account) {
    ante.emplace();
    do {
        std::cin >> ante.value();
        m_ante = ante.value();
    } while (account.getChips() < ante.value() * 2);
}

void consoleInput::betPairPlusImplementation(std::optional<int64_t> &pairPlus, bankAccount &account) {
    pairPlus.emplace();
    do {
        std::cin >> pairPlus.value();
        m_pairPlus = pairPlus.value();
    } while (account.getChips() < pairPlus.value() + m_ante * 2);
}

void consoleInput::betSixCardImplementation(std::optional<int64_t> &sixCard, bankAccount &account) {
    sixCard.emplace();
    do {
        std::cin >> sixCard.value();
        m_sixCard = sixCard.value();
    } while (account.getChips() < sixCard.value() + m_pairPlus + m_ante * 2);
}