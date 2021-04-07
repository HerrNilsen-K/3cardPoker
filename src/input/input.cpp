//
// Created by karl on 05.03.21.
//

#include "input.hpp"
#include "../player/bankAccount.hpp"

void input::betAnte(std::optional<int64_t> &ante, bankAccount &account) {
    betAnteImplementation(ante, account);
}

void input::betPairPlus(std::optional<int64_t> &pairPlus, bankAccount &account) {
    betPairPlusImplementation(pairPlus, account);
}

void input::betSixCard(std::optional<int64_t> &sixCard, bankAccount &account) {
    betSixCardImplementation(sixCard, account);
}

void input::doesPlay(char &c) {
    doesPlayImplementation(c);
}
