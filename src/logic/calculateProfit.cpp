//
// Created by karl on 06.03.21.
//

#include <variant>
#include "calculateProfit.hpp"

int64_t calculateProfit::ante(std::optional<int64_t> &ante, std::array<hand, 3> &hand) {

    return 0;
}

std::variant<handRankingAnte, cardValue> calculateProfit::getHandAnte(std::array<hand, 3> hand) {
    std::variant<handRankingAnte, cardValue> rawResult;
    std::sort(hand.begin(), hand.end(), [](struct hand i, struct hand j) -> auto {
        return i.cValue < j.cValue;
    });
    cardValue value1 = hand[0].cValue, value2 = hand[1].cValue, value3 = hand[2].cValue;
    cardType type1 = hand[0].cType, type2 = hand[1].cType, type3 = hand[2].cType;



    //Three of a kind
    if (value1 == value2 && value2 == value3)
        rawResult = handRankingAnte::THREE_OF_A_KIND;

        //Pair
    else if (value1 == value2 || value2 == value3 || value1 == value3)
        rawResult = handRankingAnte::PAIR;

        //Straight Flush
    else if ((static_cast<cardValue>(static_cast<short>(value1) + 1) == value2 &&
              static_cast<cardValue>(static_cast<short>(value2) + 1) == value3) && (type1 == type2 && type2 == type3))
        rawResult = handRankingAnte::STRAIGHT_FLUSH;

        //Straight
    else if (static_cast<cardValue>(static_cast<short>(value1) + 1) == value2 &&
             static_cast<cardValue>(static_cast<short>(value2) + 1) == value3)
        rawResult = handRankingAnte::STRAIGHT;

        //Flush
    else if (type1 == type2 && type2 == type3)
        rawResult = handRankingAnte::FLUSH;

        //High Card
    else
        rawResult = value3; //value 3 has the highest value
    return rawResult;
}
