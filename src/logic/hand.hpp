//
// Created by Karl on 03.03.2021.
//

#ifndef INC_3CARDPOKER_HAND_HPP
#define INC_3CARDPOKER_HAND_HPP

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
    SPACE,
    HEART,
    DIAMOND,

    BEGIN = CLUB,
    END = DIAMOND + 1
};

struct hand {
    cardValue cValue;
    cardType cType;
};


#endif //INC_3CARDPOKER_HAND_HPP
