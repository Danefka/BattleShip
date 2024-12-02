//
// Created by Даниил Гиршович on 10.11.2024.
//

#include "SimpleAttack.h"

bool SimpleAttack::attack(int x, int y, GameField* gameField) {
    try {
        return gameField->getDamage(x, y);
    } catch (const AttackOutOfBoundsException& e) {
        throw e;
    }
}



std::string SimpleAttack::toStr() {
    return {"Simple Attack"};
}

void SimpleAttack::setShipManager(ShipManager *shipManager) {
}

SimpleAttack::SimpleAttack() = default;
