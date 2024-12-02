//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_PLACINGSHIPSSTATE_H
#define BATTLESHIPV2_0_PLACINGSHIPSSTATE_H

#include "IState.h"
#include "../GameLogic/Game.h"

class PlacingShipsState : public IState{
public:
    PlacingShipsState(){};
    void state(Game & game) {
        game.placingShips();
    }
};
#endif //BATTLESHIPV2_0_PLACINGSHIPSSTATE_H
