//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_NEWGAMESTATE_H
#define BATTLESHIPV2_0_NEWGAMESTATE_H

#include "IState.h"
#include "../GameLogic/Game.h"

class NewGameState : public IState{
public:
    NewGameState(){};
    void state(Game & game) {
        game.startNewGame();
    }
};
#endif //BATTLESHIPV2_0_NEWGAMESTATE_H
