//
// Created by karl on 06.03.21.
//

#ifndef INC_3CARDPOKER_CALCULATEPROFIT_HPP
#define INC_3CARDPOKER_CALCULATEPROFIT_HPP


#include <cstdint>
#include <variant>
#include <array>
#include "hand.hpp"

class calculateProfit {
public:
    std::variant<handRankingAnte, cardValue> getHandAnte(std::array<hand, 3> hand);

    bool playerHasWon(short playerHand, bool playerIsHighCard, short dealerHand, bool dealerIsHighCard,
                      bool dealerDoesPlay);
    int64_t anteBonusPay(int64_t ante, short hand, bool isHighCard);

    int64_t ante(std::optional<int64_t> &ante, short hand, bool isHighCard, bool dealerPlays);

    int64_t pairPlusBonusPay(int64_t pairPlus, short hand, bool isHighCard);

    int64_t sixCardBonusPay(int64_t sixCard, std::array<hand, 6> hand);
};


#endif //INC_3CARDPOKER_CALCULATEPROFIT_HPP
