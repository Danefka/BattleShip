//
// Created by Даниил Гиршович on 29.11.2024.
//

#ifndef BATTLESHIPV2_0_CLI_H
#define BATTLESHIPV2_0_CLI_H


#include "IGraphic.h"

class CLI : public IGraphic {
public:
    CLI(GameField *gameField);
    void printMessage(std::string message);
    void printError(std::string message);
    void printField(GameField *playerField);
    void printFields(GameField *playerField, GameField *enemyField);
    CLI();
};


#endif //BATTLESHIPV2_0_CLI_H
