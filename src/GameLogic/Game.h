//
// Created by Даниил Гиршович on 29.11.2024.
//

#ifndef BATTLESHIPV2_0_GAME_H
#define BATTLESHIPV2_0_GAME_H


#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>
#include "../Field/GameField.h"
#include "../Managers/ShipManager.h"
#include "../Graphics/Graphics.h"
#include "../Managers/AttackManager.h"
#include "../Input/Input.h"


class Game {
private:
    GameField* playerField;
    ShipManager* playerShips;
    Graphics* graphics;
    AttackManager* playersAbilities;

    GameField* enemyField;
    ShipManager* enemyShips;
    Input* input;

    void newRound();
    void playerTurn();
    void enemyTurn();
    void startGame();
    void startGameFromFile();

public:
    Game();



    void startNewGame();
    nlohmann::json toJson() const;
    void from_json(const nlohmann::json& j);

    void save();
    void load();
    virtual ~Game();

};


#endif //BATTLESHIPV2_0_GAME_H
