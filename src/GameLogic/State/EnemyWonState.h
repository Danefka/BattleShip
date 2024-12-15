//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_ENEMYWONSTATE_H
#define BATTLESHIPV2_0_ENEMYWONSTATE_H

#include "IState.h"
#include "PlayerTurnState.h"

class EnemyWonState : public IState{
public:
    EnemyWonState(){};
    void state(Game & game) {
        game.youLose();

    }
};
#endif //BATTLESHIPV2_0_ENEMYWONSTATE_H
