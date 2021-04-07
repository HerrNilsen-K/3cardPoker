//
// Created by Karl on 04.03.2021.
//

#include "bets.hpp"

bets::bets()
        : m_ante(0), m_pairPlus(0), m_sixCard(0) {}

bets::bets(const std::optional<uint64_t> &ante, const std::optional<uint64_t> &pairPlus,
           const std::optional<uint64_t> &sixCard)
        : m_ante(ante.value()), m_pairPlus(pairPlus.value()), m_sixCard(sixCard.value()) {
}

uint64_t bets::getAnte() const {
    return m_ante.has_value() ? m_ante.value() : 0;
}

uint64_t bets::getPairPlus() const {
    return m_pairPlus.has_value() ? m_pairPlus.value() : 0;
}

uint64_t bets::getSixCard() const {
    return m_sixCard.has_value() ? m_sixCard.value() : 0;
}

void bets::setBets(const std::optional<uint64_t> &ante, const std::optional<uint64_t> &pairPlus,
                   const std::optional<uint64_t> &sixCard) {
    ante.has_value() ? m_ante = ante : m_ante = 0;
    pairPlus.has_value() ? m_pairPlus = pairPlus : m_pairPlus = 0;
    sixCard.has_value() ? m_sixCard = sixCard : m_sixCard = 0;
}
