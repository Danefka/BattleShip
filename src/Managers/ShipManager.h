//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_SHIPMANAGER_H
#define BATTLESHIPV2_0_SHIPMANAGER_H


#include <vector>
#include "../Ship/Ship.h"

class ShipManager {
private:
    std::vector<Ship *> ships;
public:
    explicit ShipManager(std::vector<std::pair<int, int>> pairs);
    ~ShipManager();
    int amountOfSurvivingShips();
    const std::vector<Ship*> &getShips() const;
    bool Lose();
    std::vector<int> amountShips();
    ShipManager();

    nlohmann::json toJson();
    void fromJson(const nlohmann::json& j, std::unordered_map<int, ShipSegment*>& segmentMap);
};


#endif //BATTLESHIPV2_0_SHIPMANAGER_H
