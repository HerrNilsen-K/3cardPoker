//
// Created by karl on 05.03.21.
//

#ifndef INC_3CARDPOKER_CONSOLEINPUT_HPP
#define INC_3CARDPOKER_CONSOLEINPUT_HPP


#include <optional>
#include <cstdint>
#include "../player/bankAccount.hpp"

class consoleInput {
public:
    void betAnteImplementation(std::optional<int64_t> &ante, bankAccount &account);
    void betPairPlusImplementation(std::optional<int64_t> &pairPlus, bankAccount &account);
    void betSixCardImplementation(std::optional<int64_t> &sixCard, bankAccount &account);

    void doesPlayImplementation(char &c);

private:
    int64_t m_ante, m_pairPlus, m_sixCard;

};


#endif //INC_3CARDPOKER_CONSOLEINPUT_HPP
