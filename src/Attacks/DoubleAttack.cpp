//
// Created by Даниил Гиршович on 10.11.2024.
//

#include "DoubleAttack.h"
#include "../Exceptions/ShipSegmentHasAlreadyDestroyedException.h"

DoubleAttack::DoubleAttack() = default;

bool DoubleAttack::attack(int x, int y, GameField* gameField) {
    try {
        return gameField->getDoubleDamage(x, y);
    } catch (const AttackOutOfBoundsException& e) {
        throw e;
    }
}

std::string DoubleAttack::toStr() {
    return {"Double Attack"};
}
