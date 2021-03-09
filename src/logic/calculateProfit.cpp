//
// Created by karl on 06.03.21.
//

#include <variant>
#include "calculateProfit.hpp"

int64_t calculateProfit::ante(std::optional<int64_t> &ante, short hand, bool isHighCard, bool dealerPlays) {
    if (!ante.has_value())
        return 0;
    return ante.value() * (dealerPlays ? 2 : 1.5);

}

std::variant<handRankingAnte, cardValue> calculateProfit::getHandAnte(std::array<hand, 3> hand) {
    std::variant<handRankingAnte, cardValue> rawResult;
    std::sort(hand.begin(), hand.end(), [](struct hand i, struct hand j) -> auto {
        return i.cValue < j.cValue;
    });
    cardValue value1 = hand[0].cValue, value2 = hand[1].cValue, value3 = hand[2].cValue;
    cardType type1 = hand[0].cType, type2 = hand[1].cType, type3 = hand[2].cType;



    //Straight Flush
    if ((static_cast<cardValue>(static_cast<short>(value1) + 1) == value2 &&
         static_cast<cardValue>(static_cast<short>(value2) + 1) == value3) && (type1 == type2 && type2 == type3))
        rawResult = handRankingAnte::STRAIGHT_FLUSH;

        //Straight
    else if (static_cast<cardValue>(static_cast<short>(value1) + 1) == value2 &&
             static_cast<cardValue>(static_cast<short>(value2) + 1) == value3)
        rawResult = handRankingAnte::STRAIGHT;

        //Flush
    else if (type1 == type2 && type2 == type3)
        rawResult = handRankingAnte::FLUSH;

        //Three of a kind
    else if (value1 == value2 && value2 == value3)
        rawResult = handRankingAnte::THREE_OF_A_KIND;

        //Pair
    else if (value1 == value2 || value2 == value3 || value1 == value3)
        rawResult = handRankingAnte::PAIR;

        //High Card
    else
        rawResult = value3; //value 3 has the highest value




    return rawResult;
}

int64_t calculateProfit::anteBonusPay(int64_t ante, short hand, bool isHighCard) {
    if (isHighCard)
        return 0;

    switch (hand) {
        case static_cast<short>(handRankingAnte::STRAIGHT):
            return ante + ante;
        case static_cast<short>(handRankingAnte::THREE_OF_A_KIND):
            return ante * 4 + ante;
        case static_cast<short>(handRankingAnte::STRAIGHT_FLUSH):
            return ante * 5 + ante;
        default:
            return 0;
    }
}

int64_t calculateProfit::pairPlusBonusPay(int64_t pairPlus, short hand, bool isHighCard) {
    if (isHighCard)
        return 0;

    switch (hand) {
        case static_cast<short>(pairPlusRankingAnte::STRAIGHT_FLUSH):
            return pairPlus * 40 + pairPlus;
        case static_cast<short>(pairPlusRankingAnte::THREE_OF_A_KIND):
            return pairPlus * 30 + pairPlus;
        case static_cast<short>(pairPlusRankingAnte::STRAIGHT):
            return pairPlus * 5 + pairPlus;
        case static_cast<short>(pairPlusRankingAnte::FLUSH):
            return pairPlus * 4 + pairPlus;
        case static_cast<short>(pairPlusRankingAnte::PAIR):
            return pairPlus + pairPlus;
        default:
            return 0;
    }

}

int64_t calculateProfit::sixCardBonusPay(int64_t sixCard, std::array<hand, 6> hand) {
    //Cards sorted by value
    std::sort(hand.begin(), hand.end(), [](struct hand i, struct hand j) -> auto {
        return i.cValue < j.cValue;
    });
    std::array<cardValue, 6> v{};
    for (auto i = 0; i < v.size(); ++i)
        v[i] = hand[i].cValue;

    //Cards sorted by type
    std::sort(hand.begin(), hand.end(), [](struct hand i, struct hand j) -> auto {
        return i.cType < j.cType;
    });
    std::array<cardType, 6> t{};
    for (auto i = 0; i < t.size(); ++i)
        t[i] = hand[i].cType;

    sixCard;
    //Straight Flush
    if (
            (
                    ((static_cast<short>(v[0]) == static_cast<short>(v[1]) - 1 &&
                      static_cast<short>(v[1]) == static_cast<short>(v[2]) - 1 &&
                      static_cast<short>(v[2]) == static_cast<short>(v[3]) - 1 &&
                      static_cast<short>(v[3]) == static_cast<short>(v[4]) - 1)
                     ||
                     (static_cast<short>(v[1]) == static_cast<short>(v[2]) - 1 &&
                      static_cast<short>(v[2]) == static_cast<short>(v[3]) - 1 &&
                      static_cast<short>(v[3]) == static_cast<short>(v[4]) - 1 &&
                      static_cast<short>(v[4]) == static_cast<short>(v[5]) - 1))
            ) &&
            (
                    ((t[0] == t[1] && t[1] == t[2] && t[2] == t[3] && t[3] == t[4])
                     ||
                     (t[1] == t[2] && t[2] == t[3] && t[3] == t[4] && t[4] == t[5])))
            )
        return sixCard * 200 + sixCard;
        //Four of a kind
    else if (((v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) || (v[1] == v[2] && v[2] == v[3] && v[3] == v[4])) ||
             ((v[2] == v[3] && v[3] == v[4] && v[4] == v[5]) || (v[3] == v[4] && v[4] == v[5] && v[5] == v[6])))
        return sixCard * 100 + sixCard;

        //Full House needs a new statement
        //Full House
        /*else if (((v[0] == v[1] && v[1] == v[2]) || (v[1] == v[2] && v[2] == v[3]) || (v[2] == v[3] && v[3] == v[4]) ||
                  (v[3] == v[4] && v[4] == v[5])) &&
                 ((v[0] == v[1] || v[1] == v[2] || v[2] == v[3] || v[3] == v[4] ||
                   v[4] == v[5])))
            return sixCard * 25 + sixCard;
            */

        //Flush
    else if ((t[0] == t[1] && t[1] == t[2] && t[2] == t[3] && t[3] == t[4]) ||
             (t[1] == t[2] && t[2] == t[3] && t[3] == t[4] && t[4] == t[5]))
        return sixCard * 15 + sixCard;

        //Straight
    else if ((static_cast<short>(v[0]) == static_cast<short>(v[1]) - 1 &&
              static_cast<short>(v[1]) == static_cast<short>(v[2]) - 1 &&
              static_cast<short>(v[2]) == static_cast<short>(v[3]) - 1 &&
              static_cast<short>(v[3]) == static_cast<short>(v[4]) - 1) ||
             (static_cast<short>(v[1]) == static_cast<short>(v[2]) - 1 &&
              static_cast<short>(v[2]) == static_cast<short>(v[3]) - 1 &&
              static_cast<short>(v[3]) == static_cast<short>(v[4]) - 1 &&
              static_cast<short>(v[4]) == static_cast<short>(v[5]) - 1))
        return sixCard * 10 + sixCard;

        //Three of a kind
    else if ((v[0] == v[1] && v[1] == v[2]) || (v[1] == v[2] && v[2] == v[3]) || (v[2] == v[3] && v[3] == v[4]) ||
             (v[3] == v[4] && v[4] == v[5]) || (v[4] == v[5] && v[5] == v[6]))
        return sixCard * 5 + sixCard;
    else
        return 0;

    return 0;
}

bool calculateProfit::playerHasWon(short playerHand, bool playerIsHighCard, short dealerHand, bool dealerIsHighCard) {
    if(dealerIsHighCard && !playerIsHighCard)
        return true;
    if(!dealerIsHighCard && playerIsHighCard)
        return false;

    if(playerHand > dealerHand)
        return true;

    return false;
}
