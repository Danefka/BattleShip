//
// Created by Даниил Гиршович on 10.11.2024.
//

#include "Cell.h"
#include "../../Exceptions/CellHasAlreadyAttacked.h"


Cell::Cell() {
    this->segment = nullptr;
    this->state = CellState::EMPTY;
    this->known = false;
}

bool Cell::isKnown() const {
    return this->known;
}

void Cell::setSegment(ShipSegment *segment) {
    Cell::segment = segment;
}

bool Cell::getDamage() {
    if (state == CellState::EMPTY && known) {
        throw CellHasAlreadyAttacked();
    }
    known = true;
    if (state == CellState::SHIP) {
        try {
            segment->getDamage();
        } catch (const ShipSegmentHasAlreadyDestroyedException &e) {
            throw e;
        }
        return true;
    }
    return false;
}


bool Cell::hasShip() {
    return segment != nullptr;
}

void Cell::setState(CellState state) {
    Cell::state = state;
}

CellState Cell::getState() const {
    return state;
}

std::string Cell::stateToStr() {
    if (state == CellState::EMPTY) {
        return "Empty";
    }
    return "Ship";
}

bool Cell::getDoubleDamage() {
    if (state == CellState::EMPTY && known) {
        throw CellHasAlreadyAttacked();
    }
    known = true;
    if (state == CellState::SHIP) {
        try {
            segment->getDoubleDamage();
        } catch (const ShipSegmentHasAlreadyDestroyedException &e) {
            throw e;
        }
        return true;
    }
    return false;
}

bool Cell::isDestroyed() const {
    if (state == CellState::EMPTY) {
        return isKnown();
    }
    return segment->isDestroyed();
}

bool Cell::isDamaged() const {
    if (state == CellState::EMPTY) {
        return isKnown();
    }
    return segment->isDamaged();
}

nlohmann::json Cell::toJson() const {
    nlohmann::json j;
    j["state"] = static_cast<int>(state);
    j["known"] = static_cast<bool>(known);
    if (state == CellState::SHIP) {
        j["segmentId"] = segment->toJson();
    } else { j["segmentId"] = nullptr; }
    return j;
}

// Десериализация из JSON
void Cell::fromJson(const nlohmann::json &j, const std::unordered_map<int, ShipSegment *> &segmentMap) {
    state = static_cast<CellState>(j.at("state").get<int>());
    known = j.at("known").get<bool>();
    if (state == CellState::SHIP) {
        int segmentId = j.at("segmentId").at("id").get<int>();
        segment = (segmentId != -1) ? segmentMap.at(segmentId) : nullptr;
    }
}

ShipSegment *Cell::getSegment() const {
    return segment;
}






