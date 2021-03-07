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

    int64_t  anteBonusPay(int64_t ante, short hand, bool isHighCard);
    int64_t ante(std::optional<int64_t> &ante, short hand, bool isHighCard, bool dealerPlays);
};


#endif //INC_3CARDPOKER_CALCULATEPROFIT_HPP
