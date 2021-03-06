//
// Created by Karl on 03.03.2021.
//

#ifndef INC_3CARDPOKER_HAND_HPP
#define INC_3CARDPOKER_HAND_HPP

#include <string>
#include <unordered_map>

enum class cardValue {
    TWO = 0, THREE, FOUR,
    FIVE, SIX, SEVEN,
    EIGHT, NINE, TEN,

    JACK, QUEEN, KING, ACE,

    BEGIN = TWO,
    END = ACE + 1
};

enum class cardType {
    CLUB = 0,
    SPADES,
    HEART,
    DIAMOND,

    BEGIN = CLUB,
    END = DIAMOND + 1
};

struct hand {
    cardValue cValue;
    cardType cType;
};

static std::tuple<std::string, std::string> getReadableHand(hand card) {
    static std::unordered_map<cardType, std::string> type = {
            {cardType::CLUB,    "Club"},
            {cardType::SPADES,  "Spades"},
            {cardType::HEART,   "Heart"},
            {cardType::DIAMOND, "Diamond"}
    };

    static std::unordered_map<cardValue, std::string> value = {
            {cardValue::TWO,   "2"},
            {cardValue::THREE, "3"},
            {cardValue::FOUR,  "4"},
            {cardValue::FIVE,  "5"},
            {cardValue::SIX,   "6"},
            {cardValue::SEVEN, "7"},
            {cardValue::EIGHT, "8"},
            {cardValue::NINE,  "9"},
            {cardValue::TEN,   "10"},
            {cardValue::JACK,  "Jack"},
            {cardValue::QUEEN, "Queen"},
            {cardValue::KING,  "King"},
            {cardValue::ACE,   "Ace"}
    };

    return std::make_tuple(type[card.cType], value[card.cValue]);
}


#endif //INC_3CARDPOKER_HAND_HPP
