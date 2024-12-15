//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_PLAYERWONSTATE_H
#define BATTLESHIPV2_0_PLAYERWONSTATE_H
#include "IState.h"
#include "PlayerTurnState.h"

class PlayerWonState : public IState{
public:
    PlayerWonState(){};
    void state(Game & game) {
        game.youWon();
    }
};
#endif //BATTLESHIPV2_0_PLAYERWONSTATE_H
