//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_ATTACKMANAGER_H
#define BATTLESHIPV2_0_ATTACKMANAGER_H


#include <deque>
#include <nlohmann/json.hpp>
#include "../Attacks/IAttackable.h"
#include "../Attacks/BombingAttack.h"
#include "../Attacks/DoubleAttack.h"
#include "../Attacks/ScannerAttack.h"
#include "../Attacks/SimpleAttack.h"
#include "ShipManager.h"


class AttackManager {
private:
    std::deque<IAttackable*> abilities;

public:
    AttackManager();


    std::string peek();
    IAttackable* getAbility();
    void addRandomAbility();

    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& j);
};


#endif //BATTLESHIPV2_0_ATTACKMANAGER_H
