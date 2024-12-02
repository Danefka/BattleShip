//
// Created by Даниил Гиршович on 10.11.2024.
//

#include "ShipSegment.h"

int ShipSegment::amountSegment = 0;

ShipSegment::ShipSegment() {
    this->state = SegmentState::UNDAMAGED;
    id = amountSegment;
    amountSegment++;
}

bool ShipSegment::isDestroyed() {
    return this->state == SegmentState::DESTROYED;
}

void ShipSegment::getDamage() {
    if (this->state == SegmentState::UNDAMAGED) {
        this->state = SegmentState::DAMAGED;
        return;
    }
    if (this->state == SegmentState::DAMAGED) {
        this->state = SegmentState::DESTROYED;
        return;
    }
    throw ShipSegmentHasAlreadyDestroyedException();
}

void ShipSegment::getDoubleDamage() {
    if (this->state != SegmentState::DESTROYED) {
        this->state = SegmentState::DESTROYED;
        return;
    }
    throw ShipSegmentHasAlreadyDestroyedException();

}

bool ShipSegment::isDamaged() {
    return state == SegmentState::DAMAGED;
}

nlohmann::json ShipSegment::toJson() const {
    nlohmann::json j;
    j["id"] = this->id;
    j["state"] = static_cast<int>(this->state);  // Сохраняем состояние как целое число
    return j;
}

ShipSegment ShipSegment::fromJson(const nlohmann::json& j) {
    ShipSegment segment;
    segment.id = j.at("id").get<int>();  // Восстановление ID
    segment.state = static_cast<SegmentState>(j.at("state").get<int>());
    return segment;
}

int ShipSegment::getId() const {
    return id;
}
