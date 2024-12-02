//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_GAMEFIELD_H
#define BATTLESHIPV2_0_GAMEFIELD_H


#include <vector>
#include <nlohmann/json.hpp>
#include "Cell.h"
#include "../Ship/Ship.h"
#include "../Exceptions/AttackOutOfBoundsException.h"
#include "../Exceptions/InvalidShipPlacementException.h"
#include "../Exceptions/ShipSegmentHasAlreadyDestroyedException.h"

class GameField {
private:
    std::vector<std::vector<Cell>> field;
    int width;
    int height;
public:
    GameField(int width, int height);
    void placeShip(int x, int y, Ship *ship, bool horizontal);
    bool getDamage(int x, int y);
    bool getDoubleDamage(int x, int y);


    int getWidth() const;
    int getHeight() const;
    void checkCoordinate(int x, int y);
    CellState getCellState(int x, int y);
    bool getCellKnown(int x, int y);
    bool cellDestoyed(int x, int y);
    bool cellDemaged(int x, int y);
    std::string cellStateToStr(int x, int y);


    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& j, std::unordered_map<int, ShipSegment*>& segmentMap);

    GameField();
};


#endif //BATTLESHIPV2_0_GAMEFIELD_H
