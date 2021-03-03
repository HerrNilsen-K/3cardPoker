//
// Created by karl on 03.03.21.
//

#include <fstream>
#include <iostream>
#include "bankAccount.hpp"

bankAccount::bankAccount()
        : m_chips(250) {
    //Open the file without std::fstream::in first to create if it doesn't exist
    std::fstream file("playersBankAccount.cps", std::fstream::out | std::fstream::ate);
    if (file.fail()) {
        throw std::runtime_error("File could not be opend");
    }
    file.close();
    //Probability of something happening between is so low that I don't bother adding another if/throw
    file.open("playersBankAccount.cps", std::fstream::in | std::fstream::out | std::fstream::ate);

    if (file.tellg() == 0) {
        file << m_chips;
    }

    file.seekg(0);
    int64_t chipsStored;
    file >> chipsStored;

    std::cout << chipsStored << std::endl;
}

void bankAccount::changeChipsBy(int64_t num) { m_chips += num; }

void bankAccount::setChips(int64_t num) { m_chips = num; }

int64_t bankAccount::getChips() const { return m_chips; }
