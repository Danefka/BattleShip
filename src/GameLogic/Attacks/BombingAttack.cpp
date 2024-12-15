//
// Created by Даниил Гиршович on 10.11.2024.
//

#include <iostream>
#include "BombingAttack.h"
#include "../../Utils/Random.h"
#include "../Managers/ShipManager.h"

BombingAttack::BombingAttack() {
};

bool BombingAttack::attack(int x, int y, GameField *gameField) {
    std::vector<Ship *> ships = shipManager->getShips();
    int shipIndex = Random::getRandomNumber(0, ships.size()-1);
    while (true) {
        if (!ships.at(shipIndex)->isSunk()){
            int segIndex = Random::getRandomNumber(0, ships.at(shipIndex)->getLength() - 1);
            while(true){
                try {
                    ships.at(shipIndex)->getSegment(segIndex)->getDamage();
                } catch (const ShipSegmentHasAlreadyDestroyedException& e){
                    segIndex = (segIndex+1)%(ships.at(shipIndex)->getLength());
                    continue;
                }
                return true;
            }
        }else{
            shipIndex = (shipIndex+1)%(ships.size());
        }
    }
}


std::string BombingAttack::toStr() {
    return {"Bombing Attack"};
}

void BombingAttack::setShipManager(ShipManager *shipManager) {
    BombingAttack::shipManager = shipManager;
}
