//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_SAVESTATE_H
#define BATTLESHIPV2_0_SAVESTATE_H

#include "IState.h"
#include "../GameLogic/Game.h"
#include "PlayerTurnState.h"

class SaveState : public IState{
public:
    SaveState(){};
    void state(Game & game) {
        game.save();
        game.setState(new PlayerTurnState());
    }
};

#endif //BATTLESHIPV2_0_SAVESTATE_H
