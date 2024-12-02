//
// Created by Даниил Гиршович on 10.11.2024.
//

#include "GameField.h"


GameField::GameField(int width, int height) {
    this->width = width;
    this->height = height;
    this->field = std::vector(width, std::vector<Cell>(height, Cell()));
}

bool GameField::getDamage(int x, int y) {
    if (x >= width || x < 0 || y >= height || y < 0) {
        throw AttackOutOfBoundsException();
    }
    try {
        return field.at(x).at(y).getDamage();
    } catch (const ShipSegmentHasAlreadyDestroyedException &e) {
        throw e;
    }

}

void GameField::placeShip(int x, int y, Ship *ship, bool horizontal) {
    if (horizontal) {
        if (x + ship->getLength() - 1 >= width || y >= height) {
            throw InvalidShipPlacementException("Ship out of bound");
        }
        for (int i = std::max(0, x - 1); i < std::min(width, x + ship->getLength() + 1); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(height, y + 2); ++j) {
                if (field.at(i).at(j).hasShip()) {
                    throw InvalidShipPlacementException();
                }
            }
        }
        for (int i = x; i < x + ship->getLength(); ++i) {
            field.at(i).at(y).setState(CellState::SHIP);
            field.at(i).at(y).setSegment(&ship->getSegment(i - x));
        }
    } else {

        if (y + ship->getLength() - 1 >= height || y >= width) {
            throw InvalidShipPlacementException("Ship out of bound");
        }
        for (int i = std::max(0, x - 1); i < std::min(width, x + 2); ++i) {
            for (int j = std::max(0, y - 1); j < std::min(height, y + +ship->getLength() + 1); ++j) {
                if (field.at(i).at(j).hasShip()) {
                    throw InvalidShipPlacementException();
                }
            }
        }
        for (int i = y; i < y + ship->getLength(); ++i) {
            field.at(x).at(i).setState(CellState::SHIP);
            field.at(x).at(i).setSegment(&ship->getSegment(i - y));
        }
    }
}

int GameField::getWidth() const {
    return width;
}

int GameField::getHeight() const {
    return height;
}

CellState GameField::getCellState(int x, int y) {
    return field.at(x).at(y).getState();
}

std::string GameField::cellStateToStr(int x, int y) {
    return field.at(x).at(y).stateToStr();
}

void GameField::checkCoordinate(int x, int y) {
    if (x >= width || x < 0 || y >= height || y < 0) {
        throw AttackOutOfBoundsException();
    }
}

bool GameField::getDoubleDamage(int x, int y) {
    if (x >= width || x < 0 || y >= height || y < 0) {
        throw AttackOutOfBoundsException();
    }
    try {
      return field.at(x).at(y).getDoubleDamage();
    } catch (const ShipSegmentHasAlreadyDestroyedException &e) {
        throw e;
    }
}

bool GameField::getCellKnown(int x, int y) {
    return field.at(x).at(y).isKnown();
}

bool GameField::cellDestoyed(int x, int y) {
    return field.at(x).at(y).isDestroyed();
}

bool GameField::cellDemaged(int x, int y) {
    return field.at(x).at(y).isDamaged();
}

GameField::GameField() = default;



nlohmann::json GameField::toJson() const {
    nlohmann::json fieldJson = nlohmann::json::array();

    // Сериализация клеток с состоянием и связями
    for (const auto& row : field) {
        nlohmann::json rowJson = nlohmann::json::array();
        for (const auto& cell : row) {
            rowJson.push_back(cell.toJson());  // Сериализуем каждую клетку с её ссылкой на сегмент
        }
        fieldJson.push_back(rowJson);
    }

    return {
            {"width", width},
            {"height", height},
            {"field", fieldJson}
    };
}

void GameField::fromJson(const nlohmann::json& j,std::unordered_map<int, ShipSegment*>& segmentMap) {
    this->width = j.at("width").get<int>();
    this->height = j.at("height").get<int>();
    this->field = std::vector(width, std::vector<Cell>(height, Cell()));

    const auto& fieldJson = j.at("field");
    for (size_t y = 0; y < fieldJson.size(); ++y) {
        for (size_t x = 0; x < fieldJson[y].size(); ++x) {
            field.at(x).at(y).fromJson(fieldJson[x][y], segmentMap);
        }
    }
}
