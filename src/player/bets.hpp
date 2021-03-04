//
// Created by Karl on 04.03.2021.
//

#ifndef INC_3CARDPOKER_BETS_HPP
#define INC_3CARDPOKER_BETS_HPP


#include <cstdint>
#include <optional>

class bets {
public:
    bets();

    explicit bets(const std::optional<uint64_t> &ante, const std::optional<uint64_t> &pairPlus = {0},
                  const std::optional<uint64_t> &sixCard = {0});

    void setBets(const std::optional<uint64_t> &ante, const std::optional<uint64_t> &pairPlus,
                 const std::optional<uint64_t> &sixCard);

    [[nodiscard]]

    uint64_t getAnte() const;

    [[nodiscard]] uint64_t getPairPlus() const;

    [[nodiscard]] uint64_t getSixCard() const;

private:
    std::optional<uint64_t> m_ante, m_pairPlus, m_sixCard;
};


#endif //INC_3CARDPOKER_BETS_HPP
