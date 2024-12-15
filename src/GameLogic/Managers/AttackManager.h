//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_ATTACKMANAGER_H
#define BATTLESHIPV2_0_ATTACKMANAGER_H


#include <deque>
#include <nlohmann/json.hpp>
#include "ShipManager.h"
#include "../Attacks/IAttackable.h"
#include "../Attacks/BombingAttack.h"
#include "../Attacks/DoubleAttack.h"
#include "../Attacks/ScannerAttack.h"
#include "../Attacks/SimpleAttack.h"
#include "../../CLI/IGraphic.h"


class AttackManager {
private:
    Output<IGraphic> *output;
    std::deque<IAttackable*> abilities;
public:
    AttackManager(Output<IGraphic> *output);


    std::string peek();
    IAttackable* getAbility();
    void addRandomAbility();

    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& j);
};


#endif //BATTLESHIPV2_0_ATTACKMANAGER_H
