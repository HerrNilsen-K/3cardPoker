//
// Created by karl on 05.03.21.
//

#ifndef INC_3CARDPOKER_INPUT_HPP
#define INC_3CARDPOKER_INPUT_HPP


#include <optional>
#include <cstdint>
#include "consoleInput.hpp"
#include "../player/bankAccount.hpp"

class input : consoleInput{
public:
    void betAnte(std::optional<int64_t> &ante, bankAccount &account);
    void betPairPlus(std::optional<int64_t> &pairPlus, bankAccount &account);
    void betSixCard(std::optional<int64_t> &sixCard, bankAccount &account);

    void doesPlay(char &c);
};


#endif //INC_3CARDPOKER_INPUT_HPP
