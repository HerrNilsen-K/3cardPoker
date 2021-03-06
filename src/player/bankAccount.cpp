//
// Created by karl on 03.03.21.
//

#include <fstream>
#include <iostream>
#include "bankAccount.hpp"

bankAccount::bankAccount()
        : m_chips(250) {
    //Open the file without std::fstream::in first to create if it doesn't exist
    std::fstream file(m_fileName, std::fstream::out | std::fstream::app);
    if (file.fail()) {
        throw std::runtime_error("File could not be opend");
    }
    file.close();
    //Probability of something happening between is so low that I don't bother adding another if/throw
    file.open(m_fileName, std::fstream::in | std::fstream::out | std::fstream::ate);

    if (file.tellg() == 0) {
        file << m_chips;
    }
    file.seekg(0);
    file >> m_chips;

    file.close();
}

void bankAccount::changeChipsBy(int64_t num) {
    m_chips += num;
    setFile();
}

void bankAccount::setChips(int64_t num) {
    m_chips = num;
    setFile();
}

int64_t bankAccount::getChips() const { return m_chips; }

void bankAccount::setFile() const {
    std::fstream file(m_fileName, std::fstream::in);
    if (file.fail())
        throw std::runtime_error("File could not be opend");
    int64_t chips;
    file >> chips;
    file.close();

    //Delete files content
    file.open(m_fileName, std::fstream::out | std::fstream::trunc);
    file.close();

    file.open(m_fileName, std::fstream::out | std::fstream::app);
    file << m_chips;
    file.close();
}
