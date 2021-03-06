//
// Created by karl on 06.03.21.
//

#ifndef INC_3CARDPOKER_CALCULATEPROFIT_HPP
#define INC_3CARDPOKER_CALCULATEPROFIT_HPP


#include <cstdint>
#include <optional>
#include <array>
#include "hand.hpp"

class calculateProfit {
public:
    int64_t ante(std::optional<int64_t> &ante, std::array<hand, 3>& hand);

};


#endif //INC_3CARDPOKER_CALCULATEPROFIT_HPP
