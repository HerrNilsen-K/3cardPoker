//
// Created by Karl on 06.03.2021.
//

#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
#include "cardsDeck.hpp"
#include "../logic/randomGenerator.hpp"

cardsDeck::cardsDeck() {
    //Create a poker card deck consisting of 52 cards
    for (int i = static_cast<int>(cardType::BEGIN); i < static_cast<int>(cardType::END); ++i) {
        for (int j = static_cast<int>(cardValue::BEGIN); j < static_cast<int>(cardValue::END); ++j) {
            hand temp{static_cast<cardValue>(j), static_cast<cardType>(i)};
            m_deck.push_back(temp);
        }
    }
}

void cardsDeck::shuffleDeck() {
    std::shuffle(m_deck.begin(), m_deck.end(),
                 std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
}

std::vector<hand> cardsDeck::drawCards(int n) {
    std::vector<hand> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = m_deck.front();
        m_deck.pop_front();
    }
    return result;
}
