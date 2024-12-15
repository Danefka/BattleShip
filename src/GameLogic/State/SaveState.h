//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_SAVESTATE_H
#define BATTLESHIPV2_0_SAVESTATE_H

#include "IState.h"
#include "../Game.h"
#include "PlayerTurnState.h"

class SaveState : public IState {
public:
    SaveState() {};

    void state(Game &game) {
        try {
            game.save();
            game.setState(new PlayerTurnState());
        } catch (std::runtime_error &e) {
            game.setState(new NewGameState());
        }
    }
};

#endif //BATTLESHIPV2_0_SAVESTATE_H
