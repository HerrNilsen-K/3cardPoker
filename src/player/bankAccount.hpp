//
// Created by karl on 03.03.21.
//

#ifndef INC_3CARDPOKER_BANKACCOUNT_HPP
#define INC_3CARDPOKER_BANKACCOUNT_HPP


#include <cstdint>

class bankAccount {
public:
    bankAccount();

    void changeChipsBy(int64_t num);

    void setChips(int64_t num);

    [[nodiscard]] int64_t getChips() const;

private:
    int64_t m_chips;

};


#endif //INC_3CARDPOKER_BANKACCOUNT_HPP
