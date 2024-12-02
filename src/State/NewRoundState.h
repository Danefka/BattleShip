//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_NEWROUNDSTATE_H
#define BATTLESHIPV2_0_NEWROUNDSTATE_H

#include "IState.h"
#include "PlayerTurnState.h"

class NewRoundState : public IState{
public:
    NewRoundState(){};
    void state(Game & game) {
        game.newRound();
    }
};
#endif //BATTLESHIPV2_0_NEWROUNDSTATE_H
