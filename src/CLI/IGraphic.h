//
// Created by Даниил Гиршович on 15.12.2024.
//

#ifndef BATTLESHIPV2_0_IGRAPHIC_H
#define BATTLESHIPV2_0_IGRAPHIC_H

#include "../GameLogic/Field/GameField.h"

class IGraphic {
public:
    virtual void printMessage(std::string message) = 0;
    virtual void printError(std::string message) = 0;
    virtual void printField(GameField *playerField) = 0;
    virtual void printFields(GameField *playerField, GameField *enemyField) = 0;
};

#endif //BATTLESHIPV2_0_IGRAPHIC_H
