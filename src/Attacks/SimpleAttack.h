//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_SIMPLEATTACK_H
#define BATTLESHIPV2_0_SIMPLEATTACK_H


#include "IAttackable.h"

class SimpleAttack : public IAttackable{
public:
    SimpleAttack();
    virtual void setShipManager(ShipManager *shipManager) override;
    bool attack(int x, int y, GameField* gameField) override;
    std::string toStr() override;
};


#endif //BATTLESHIPV2_0_SIMPLEATTACK_H
