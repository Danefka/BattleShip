//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_SCANNERATTACK_H
#define BATTLESHIPV2_0_SCANNERATTACK_H


#include "IAttackable.h"

class ScannerAttack: public IAttackable{
public:
    ScannerAttack();
    virtual void setShipManager(ShipManager *shipManager) override {}
    bool attack(int x, int y, GameField* gameField) override;
    std::string toStr() override;
};


#endif //BATTLESHIPV2_0_SCANNERATTACK_H
