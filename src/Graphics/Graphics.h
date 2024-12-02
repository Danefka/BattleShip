//
// Created by Даниил Гиршович on 29.11.2024.
//

#ifndef BATTLESHIPV2_0_GRAPHICS_H
#define BATTLESHIPV2_0_GRAPHICS_H


#include "../Field/GameField.h"

class Graphics {
private:
    GameField* playerField;
    GameField* enemyField;
public:
    Graphics(GameField* gameField);

    void setEnemyField(GameField *enemyField);

    void startGamePrint();
    void print();
    Graphics();
};


#endif //BATTLESHIPV2_0_GRAPHICS_H
