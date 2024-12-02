//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_IATTACKABLE_H
#define BATTLESHIPV2_0_IATTACKABLE_H

#include "../Field/GameField.h"
#include "../Exceptions/AttackOutOfBoundsException.h"
#include "../Managers/ShipManager.h"

class IAttackable{
public:
    virtual bool attack(int x, int y, GameField* gameField) = 0;
    virtual std::string toStr() = 0;
    virtual void setShipManager(ShipManager *shipManager) = 0;
};
#endif //BATTLESHIPV2_0_IATTACKABLE_H
