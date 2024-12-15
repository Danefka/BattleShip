//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_SHIPSEGMENT_H
#define BATTLESHIPV2_0_SHIPSEGMENT_H

#include <iostream>
#include <nlohmann/json.hpp>
#include "../../Exceptions/ShipSegmentHasAlreadyDestroyedException.h"

enum class SegmentState {UNDAMAGED, DAMAGED, DESTROYED};

class ShipSegment {
private:
    static int amountSegment;
    SegmentState state;
    int id;
public:
    ShipSegment();
    bool isDestroyed();
    void getDamage();
    void getDoubleDamage();

    int getId() const;

    bool isDamaged();

    nlohmann::json toJson() const;
    static ShipSegment fromJson(const nlohmann::json& j);
};


#endif //BATTLESHIPV2_0_SHIPSEGMENT_H
