//
// Created by Даниил Гиршович on 29.11.2024.
//

#ifndef BATTLESHIPV2_0_GAME_H
#define BATTLESHIPV2_0_GAME_H



#include <nlohmann/json.hpp>
#include "Field/GameField.h"
#include "Managers/ShipManager.h"
#include "../CLI/CLI.h"
#include "Managers/AttackManager.h"
#include "../Input/Input.h"
#include "State/IState.h"
#include "../Output/Output.h"


class Game {
private:
    GameField* playerField;
    ShipManager* playerShips;
    Output<IGraphic>* output;

    AttackManager* playersAbilities;

    GameField* enemyField;
    ShipManager* enemyShips;
    IState * state;
    Input* input;
public:
    void setState(IState *state);
    Game(Input *input, Output<IGraphic> *output);
    void newRound();
    void playerTurn();
    void enemyTurn();
    void placingShips();
    void startGameFromFile();


    void startNewGame();
    nlohmann::json toJson() const;
    void from_json(const nlohmann::json& j);
    void youWon();
    void youLose();
    void save();
    void load();
    virtual ~Game();

    IState *getState() const;

    void doState();
};


#endif //BATTLESHIPV2_0_GAME_H
