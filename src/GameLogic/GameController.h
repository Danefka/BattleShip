//
// Created by Даниил Гиршович on 15.12.2024.
//

#ifndef BATTLESHIPV2_0_GAMECONTROLLER_H
#define BATTLESHIPV2_0_GAMECONTROLLER_H

#include "Game.h"
#include "../Output/Output.h"
#include "State/NewGameState.h"
#include "State/PlacingShipsState.h"
#include "State/NewRoundState.h"
#include "State/PlayerWonState.h"
#include "State/EnemyWonState.h"

template<typename InputClass, typename OutputClass>
class GameController {
private:
    Game *game;
    OutputClass *outputClass;
    InputClass *inputClass;
public:
    GameController(Game *game, OutputClass *outputClass, InputClass *inputClass) : game(game), outputClass(outputClass),
                                                                                   inputClass(
                                                                                           inputClass) { inputCommand(); }

    void inputCommand() {

        Command current_command = inputClass->inputCommand();
        checkCommand(current_command);
        inputCommand();
    }

    void checkCommand(Command current_command) {
        switch (current_command) {
            case NEW_GAME:
                game->startNewGame();
                if (dynamic_cast<PlacingShipsState *>(game->getState())) {
                    game->placingShips();
                }
                if (dynamic_cast<NewRoundState *>(game->getState())) {
                    game->newRound();
                }
                break;
            case SAVE:
                if (!dynamic_cast<NewGameState *>(game->getState())) {
                    game->save();
                    break;
                }
                outputClass->printMessage("nothing to save");
                break;
            case LOAD:
                game->startGameFromFile();
                break;
            case QUIT:
                exit(0);
            case START_GAME:
                if (dynamic_cast<NewGameState *>(game->getState()) or dynamic_cast<EnemyWonState *>(game->getState())) {
                    outputClass->printError("You have to create a new game");
                    break;
                }

                while (true) {
                    game->doState();
                    if (dynamic_cast<NewGameState *>(game->getState()) or
                        dynamic_cast<EnemyWonState *>(game->getState()) or dynamic_cast<PlayerWonState *>(game->getState())) {
                        break;
                    }
                }

                break;

            case HELP:
                outputClass->help();
                break;
            case SILENT:
                while (true) {
                    game->doState();
                }
        }
    }
};

#endif //BATTLESHIPV2_0_GAMECONTROLLER_H
