//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_BOMBINGATTACK_H
#define BATTLESHIPV2_0_BOMBINGATTACK_H


#include "IAttackable.h"
#include "../Managers/ShipManager.h"

class BombingAttack : public IAttackable {
private:
    ShipManager *shipManager;
public:
    BombingAttack();

    void setShipManager(ShipManager *shipManager) override;

    bool attack(int x, int y, GameField *gameField) override;
    std::string toStr() override;
};


#endif //BATTLESHIPV2_0_BOMBINGATTACK_H
