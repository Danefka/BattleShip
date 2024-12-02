//
// Created by Даниил Гиршович on 10.11.2024.
//
#include "Ship.h"

Ship::Ship(int length) {
    if (length < 1 || length > 4) {
        throw std::invalid_argument((std::ostringstream() << "Invalid ship length: " << length).str());
    }
    this->length = length;
    this->shipSegments = std::vector<ShipSegment>(length);
}

bool Ship::isSunk() {
    for (auto segment: this->shipSegments) {
        if (!segment.isDestroyed()) {
            return false;
        }
    }
    return true;
}

int Ship::getLength() const {
    return length;
}

ShipSegment &Ship::getSegment(int index) {
    return shipSegments.at(index);
}

Ship::~Ship() = default;

nlohmann::json Ship::toJson() const {
    nlohmann::json j;
    j["length"] = length;
    j["segmentIds"] = nlohmann::json::array();
    for (const auto& segment : shipSegments) {
        j["segmentIds"].push_back(segment.getId());  // Сохраняем ID сегментов
    }
    return j;
}

Ship Ship::fromJson(const nlohmann::json& j, const std::unordered_map<int, ShipSegment*>& segmentMap) {
    Ship ship(j.at("length").get<int>());
    const auto& segmentIds = j.at("segmentIds");
    ship.shipSegments.clear();
    for (const auto& segmentId : segmentIds) {
        ship.shipSegments.push_back(*segmentMap.at(segmentId.get<int>()));  // Восстанавливаем сегменты по ID
    }
    return ship;
}