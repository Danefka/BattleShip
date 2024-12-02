//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_LOADSTATE_H
#define BATTLESHIPV2_0_LOADSTATE_H

#include "IState.h"
#include "PlayerTurnState.h"

class LoadState : public IState{
public:
    LoadState(){};
    void state(Game & game) {
        game.startGameFromFile();
        game.setState(new PlayerTurnState);
    }
};
#endif //BATTLESHIPV2_0_LOADSTATE_H
