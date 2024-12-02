//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_SHIP_H
#define BATTLESHIPV2_0_SHIP_H

#include <vector>
#include "ShipSegment.h"
#include <sstream>

class Ship {
private:
    int length;
    std::vector<ShipSegment> shipSegments;
public:
    Ship(int length);
    ~Ship();

    int getLength() const;
    ShipSegment& getSegment(int index);
    bool isSunk();

    nlohmann::json toJson() const;
    static Ship fromJson(const nlohmann::json& j, const std::unordered_map<int, ShipSegment*>& segmentMap);

};


#endif //BATTLESHIPV2_0_SHIP_H
