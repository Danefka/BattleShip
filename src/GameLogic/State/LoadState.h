//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_LOADSTATE_H
#define BATTLESHIPV2_0_LOADSTATE_H

#include "IState.h"
#include "PlayerTurnState.h"
#include "NewGameState.h"

class LoadState : public IState {
public:
    LoadState() {};

    void state(Game &game) {
        try {
            game.startGameFromFile();
            game.setState(new PlayerTurnState);
        } catch (std::runtime_error &e) {
            game.setState(new NewGameState());
        }
    }
};

#endif //BATTLESHIPV2_0_LOADSTATE_H
