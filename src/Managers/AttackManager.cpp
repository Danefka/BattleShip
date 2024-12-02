//
// Created by Даниил Гиршович on 10.11.2024.
//

#include <iostream>
#include "AttackManager.h"
#include "../Exceptions/NoAvailableAbilityException.h"
#include "../Utils/Random.h"
#include <algorithm>
#include <iterator>
#include <random>

AttackManager::AttackManager() {
    abilities.push_back(new BombingAttack());
    abilities.push_back(new DoubleAttack());
    abilities.push_back(new ScannerAttack());
    std::shuffle(abilities.begin(), abilities.end(), std::mt19937(static_cast<unsigned int>(time(0))));
}

IAttackable *AttackManager::getAbility() {
    if (abilities.empty()) {
        throw NoAvailableAbilityException();
    }
    IAttackable *ability = abilities.front();
    abilities.pop_front();
    return ability;
}

void AttackManager::addRandomAbility() {
    int random = Random::getRandomNumber(0, 2);
    switch (random) {
        case (0): {
            BombingAttack* bombingAttack = new BombingAttack();
            abilities.push_back(bombingAttack);
            std::cout << "\e[1;36madd a bombing attack in your bag \e[0m" << std::endl;
            return;
        }
        case (1): {
            DoubleAttack* doubleAttack = new DoubleAttack();
            abilities.push_back(doubleAttack);
            std::cout << "\e[1;36madd a double attack in your bag \e[0m" << std::endl;
            return;
        }
        case (2): {
            ScannerAttack* scannerAttack = new ScannerAttack();
            abilities.push_back(scannerAttack);
            std::cout << "\e[1;36madd a scanner attack in your bag \e[0m" << std::endl;
            return;
        }
        default: {
            return;
        }
    }
}

std::string AttackManager::peek() {
    if (abilities.empty()){
        throw NoAvailableAbilityException();
    }
    IAttackable* ability = abilities.front();
    return ability->toStr();
}




nlohmann::json AttackManager::toJson() const {
    nlohmann::json j;


    nlohmann::json abilitiesJson = nlohmann::json::array();
    for (const auto& ability : abilities) {
        abilitiesJson.push_back(ability->toStr());
    }

    j["abilities"] = abilitiesJson;

    return j;
}

void AttackManager::fromJson(const nlohmann::json& j) {
    this->abilities.clear();

    const auto& abilitiesJson = j.at("abilities");

    for (const auto& abilityType : abilitiesJson) {
        if (abilityType == "Double Attack") {
            this->abilities.push_back(new DoubleAttack());
        } else if (abilityType == "Bombing Attack") {
            this->abilities.push_back(new BombingAttack());
        } else if (abilityType == "Scanner Attack") {
            this->abilities.push_back(new ScannerAttack());
        }
    }

}



