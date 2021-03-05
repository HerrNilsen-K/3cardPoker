//
// Created by karl on 05.03.21.
//

#include "input.hpp"

void input::betAnte(std::optional<int64_t> &ante) {
    betAnteImplementation(ante);
}

void input::betPairPlus(std::optional<int64_t> &pairPlus) {
    betAnteImplementation(pairPlus);
}

void input::betSixCard(std::optional<int64_t> &sixCard) {
    betAnteImplementation(sixCard);
}
