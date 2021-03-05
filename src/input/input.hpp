//
// Created by karl on 05.03.21.
//

#ifndef INC_3CARDPOKER_INPUT_HPP
#define INC_3CARDPOKER_INPUT_HPP


#include <optional>
#include <cstdint>
#include "consoleInput.hpp"

class input : consoleInput{
public:
    void betAnte(std::optional<int64_t> &ante);
    void betPairPlus(std::optional<int64_t> &pairPlus);
    void betSixCard(std::optional<int64_t> &sixCard);

};


#endif //INC_3CARDPOKER_INPUT_HPP
