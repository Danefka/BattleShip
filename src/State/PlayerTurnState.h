//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_PLAYERTURNSTATE_H
#define BATTLESHIPV2_0_PLAYERTURNSTATE_H

#include "../Input/Input.h"
#include "IState.h"
#include "../GameLogic/Game.h"

class PlayerTurnState : public IState{
public:
    PlayerTurnState(){};
    void state(Game & game) {
        game.playerTurn();
    }
};
#endif //BATTLESHIPV2_0_PLAYERTURNSTATE_H
