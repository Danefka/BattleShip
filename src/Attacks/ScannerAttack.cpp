//
// Created by Даниил Гиршович on 10.11.2024.
//

#include <iostream>
#include "ScannerAttack.h"

bool ScannerAttack::attack(int x, int y, GameField* gameField) {
    for (int j = std::max(0, y - 1); j < std::min(gameField->getHeight(), y + 2); ++j) {
        for (int i = std::max(0, x - 1); i < std::min(gameField->getWidth(), x + 2); ++i) {
            if( gameField->getCellState(i,j) == CellState::SHIP){
                std::cout << "There is a ship" << std::endl;
                return false;
            }
        }
    }
    std::cout << "This area has no ships" << std::endl;
    return false;
}

std::string ScannerAttack::toStr() {
    return {"Scanner Attack"};
}

ScannerAttack::ScannerAttack() = default;
