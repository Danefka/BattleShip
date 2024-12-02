//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_CELL_H
#define BATTLESHIPV2_0_CELL_H

#include <string>
#include <nlohmann/json.hpp>
#include "../Ship/ShipSegment.h"
#include "../Exceptions/ShipSegmentHasAlreadyDestroyedException.h"

enum class CellState {EMPTY, SHIP};

class Cell {
private:
    CellState state;
    ShipSegment* segment;
    bool known;
public:
    Cell();

    bool isKnown() const;
    bool isDestroyed() const;
    bool getDamage();
    bool getDoubleDamage();
    void setSegment(ShipSegment *segment);

    void setState(CellState state);

    bool hasShip();

    CellState getState() const;
    std::string stateToStr();

    bool isDamaged() const;

    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& j, const std::unordered_map<int, ShipSegment*>& segmentMap);

    ShipSegment *getSegment() const;
};


#endif //BATTLESHIPV2_0_CELL_H
