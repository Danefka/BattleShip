//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_ENEMYTURNSTATE_H
#define BATTLESHIPV2_0_ENEMYTURNSTATE_H

#include "../../Input/Input.h"
#include "IState.h"
#include "../Game.h"

class EnemyTurnState : public IState{
public:
    EnemyTurnState(){};
    void state(Game & game) {
        game.enemyTurn();
    }
};
#endif //BATTLESHIPV2_0_ENEMYTURNSTATE_H
