//
// Created by Даниил Гиршович on 10.11.2024.
//

#include "ShipManager.h"

ShipManager::ShipManager(std::vector<std::pair<int, int>> pairs) {
    for (std::pair pair: pairs) {
        while (pair.second > 0) {
            pair.second--;
            this->ships.push_back(new Ship(pair.first));
        }
    }
}

bool ShipManager::Lose() {
    for (Ship *ship:ships) {
        if (!ship->isSunk()){
            return false;
        }
    }
    printf("Game over");
    return true;
}

const std::vector<Ship*> &ShipManager::getShips() const {
    return ships;
}

int ShipManager::amountOfSurvivingShips() {
    int amount = 0;
    for (Ship *ship: ships) {
        if (!ship->isSunk()){amount++;}
    }
    return amount;
}

std::vector<int> ShipManager::amountShips() {
    std::vector<int> *amountShips = new std::vector<int>(4);
    for (Ship* ship: ships){
        amountShips->at(4 -ship->getLength())++;
    }
    return *amountShips;
}

ShipManager::ShipManager() = default;


ShipManager::~ShipManager() = default;


nlohmann::json ShipManager::toJson() {
    nlohmann::json shipsJson;
    shipsJson = nlohmann::json::array();
    for (size_t i = 0; i < ships.size(); ++i) {
        shipsJson.push_back(ships[i]->toJson());
    }

    return {
            {"ships", shipsJson}
    };
}

void ShipManager::fromJson(const nlohmann::json& j, std::unordered_map<int, ShipSegment*>& segmentMap) {
    this->ships.clear();
    const auto& shipsJson = j.at("ships");
    for (const auto& shipJson : shipsJson) {
        ships.push_back(new Ship(Ship::fromJson(shipJson, segmentMap)));
    }
}