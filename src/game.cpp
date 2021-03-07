//
// Created by Karl on 03.03.2021.
//

#include <array>
#include "game.h"
#include "logic/cardShuffler.h"
#include "logic/hand.hpp"
#include "player/bankAccount.hpp"
#include "player/bets.hpp"
#include "renderer/renderer.hpp"
#include "input/input.hpp"
#include "cards/cardsDeck.hpp"
#include "logic/calculateProfit.hpp"


void game::run() {
    bool gameIsRrunning = true;
    cardShuffler cs;
    bankAccount playersBank;
    bets bet;
    renderer render;
    input in;
    cardsDeck deck;
    calculateProfit profit;


    while (gameIsRrunning) {
        //Take in the players bets
        render.currentChips(playersBank.getChips());
        render.bets();

        std::optional<int64_t> ante, pairPlus, sixCard;
        render.betAnte();
        in.betAnte(ante, playersBank);
        render.betPairPlus();
        in.betPairPlus(pairPlus, playersBank);
        render.betSixCard();
        in.betSixCard(sixCard, playersBank);
        playersBank.changeChipsBy((-ante.value()) + (-pairPlus.value()) + -(sixCard.value()));


        //Spread the cards
        deck.shuffleDeck();
        std::array<hand, 3> dealer{};
        std::vector<hand> tempDealer = deck.drawCards(3);
        std::copy(tempDealer.begin(), tempDealer.end(), dealer.data());
        std::array<hand, 3> player{};
        std::vector<hand> tempPlayer = deck.drawCards(3);
        std::copy(tempPlayer.begin(), tempPlayer.end(), player.data());

        render.showPlayersCards(player);
        render.doesPlay();


        //Player devides to doesPlay or not
        char doesPlay;
        in.doesPlay(doesPlay);
        bool plays = (doesPlay == 'y' || doesPlay == 'Y');
        render.showDealersCards(dealer);

        //Calculate players profit
        int64_t anteProfit;
        if (plays) {
            anteProfit = profit.ante(ante, player);
        }
        std::array<hand, 3> temp = {
                {
                        {cardValue::NINE, cardType::HEART},
                        {cardValue::TWO, cardType::SPADES},
                        {cardValue::SEVEN, cardType::SPADES}
                }
        };

        //paiPlusProfit = profit.paiPlus(paiPlus, player);
        //sixCardProfit = profit.sixCard(sixCard, player, dealer);


        gameIsRrunning = false;
    }
}
