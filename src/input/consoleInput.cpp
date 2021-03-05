//
// Created by karl on 05.03.21.
//

#include <iostream>
#include "consoleInput.hpp"

void consoleInput::betAnteImplementation(std::optional<int64_t> &ante) {
    std::cin >> ante.value();
}

void consoleInput::betPairPlusImplementation(std::optional<int64_t> &pairPlus) {
    std::cin >> pairPlus.value();

}

void consoleInput::betSixCardImplementation(std::optional<int64_t> &sixCard) {
    std::cin >> sixCard.value();
}
