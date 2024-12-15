//
// Created by Даниил Гиршович on 02.12.2024.
//

#ifndef BATTLESHIPV2_0_ISTATE_H
#define BATTLESHIPV2_0_ISTATE_H


#include "../../Input/Input.h"
#include "../Game.h"
class Game;
class IState{
public:
    virtual void state(Game &game) = 0;
};
#endif //BATTLESHIPV2_0_ISTATE_H
