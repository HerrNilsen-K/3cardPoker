//
// Created by Karl on 03.03.2021.
//

#ifndef INC_3CARDPOKER_HAND_H
#define INC_3CARDPOKER_HAND_H

enum cardValue {
    ZERO = 0,
    ONE, TWO, THREE,
    FOUR, FIVE, SIX,
    SEVEN, EIGHT, NINE, TEN,

    JACK, QUEEN, KING,

    ACE
};

enum cardType {
    CLUB = 0,
    SPACE,
    HEART,
    DIAMOND
};

struct hand {
    cardValue m_hv;
    cardType m_ct;
};


#endif //INC_3CARDPOKER_HAND_H
