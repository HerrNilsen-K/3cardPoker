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
        std::array<hand, 3> dealersHand{};
        std::vector<hand> tempDealer = deck.drawCards(3);
        std::copy(tempDealer.begin(), tempDealer.end(), dealersHand.data());
        std::array<hand, 3> playersHand{};
        std::vector<hand> tempPlayer = deck.drawCards(3);
        std::copy(tempPlayer.begin(), tempPlayer.end(), playersHand.data());

        render.showPlayersCards(playersHand);
        render.doesPlay();


        //Player devides to playerDoesPlay or not
        char playerDoesPlay;
        in.doesPlay(playerDoesPlay);
        bool plays = (playerDoesPlay == 'y' || playerDoesPlay == 'Y');
        render.showDealersCards(dealersHand);



        //Calculate players profit
        bool playerIsHighCard = false;
        short playerAnteResult;
        try {
            playerAnteResult = static_cast<short>(std::get<handRankingAnte>(profit.getHandAnte(playersHand)));
        } catch (std::bad_variant_access const &e) {
            playerAnteResult = static_cast<short>(std::get<cardValue>(profit.getHandAnte(playersHand)));
            playerIsHighCard = true;
        }

        bool dealerIsHighCard = false, dealerDoesPlay = true;
        short dealerAnteResult;
        try {
            dealerAnteResult = static_cast<short>(std::get<handRankingAnte>(profit.getHandAnte(dealersHand)));
        } catch (std::bad_variant_access const &e) {
            dealerAnteResult = static_cast<short>(std::get<cardValue>(profit.getHandAnte(dealersHand)));
            dealerIsHighCard = true;
            if(dealerAnteResult < static_cast<short>(cardValue::QUEEN))
                playerDoesPlay = false;
        }

        int64_t anteProfit = 0, pairPlusProfit = 0;
        if (plays) {
            anteProfit = profit.ante(ante, playerAnteResult, playerIsHighCard, dealerDoesPlay);
        }

        anteProfit += profit.anteBonusPay(ante.value(), playerAnteResult, playerIsHighCard);
        pairPlusProfit += profit.pairPlusBonusPay(pairPlus.value(), playerAnteResult, playerIsHighCard);

        //paiPlusProfit = profit.paiPlus(paiPlus, playersHand);
        //sixCardProfit = profit.sixCard(sixCard, playersHand, dealersHand);


        gameIsRrunning = false;
    }
}
