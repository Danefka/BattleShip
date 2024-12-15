//
// Created by Даниил Гиршович on 29.11.2024.
//

#include "CLI.h"

CLI::CLI(GameField *gameField) {};

void CLI::printFields(GameField* playerField, GameField* enemyField) {
    std::cout << std::endl;
    for (int i = playerField->getWidth() * 10; i > 0; i /= 10) {
        std::cout << " ";
    }
    for (int i = 0; i < playerField->getWidth(); ++i) {
        std::cout << i + 1 << " ";
    }
    std::cout << "    ";
    for (int i = 0; i < playerField->getWidth(); ++i) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < playerField->getHeight(); ++i) {
        if (playerField->getHeight() > 9) {
            if (i < 9) {
                std::cout << i + 1;
                for (int i = playerField->getWidth() * 10; i > 0; i /= 10) {
                    std::cout << " ";
                }
            } else {
                std::cout << i + 1;
                for (int i = playerField->getWidth(); i > 0; i /= 10) {
                    std::cout << " ";
                }
            }
        } else {
                std::cout << i + 1 << " ";
        }
        for (int j = 0; j < playerField->getWidth(); ++j) {
            if (playerField->getCellState(j, i) == CellState::EMPTY) {
                if (playerField->getCellKnown(j, i)) {
                    std::cout << "o ";
                } else {
                    std::cout << ". ";
                }
            } else {
                if (playerField->cellDestoyed(j, i)) {
                    std::cout << "\e[1;31mX \e[0m";
                } else if (playerField->cellDemaged(j, i)) {
                    std::cout << "\e[1;33mX \e[0m";
                } else {
                    std::cout << "X ";
                }
            }
        }
        std::cout << "    ";
        for (int j = 0; j < enemyField->getWidth(); ++j) {
            if (!enemyField->getCellKnown(j, i)) {
                std::cout << ". ";
            } else if (enemyField->getCellState(j, i) == CellState::EMPTY) {
                std::cout << "o ";
            } else {
                if (enemyField->cellDestoyed(j, i)) {
                    std::cout << "\e[1;31mX \e[0m";
                } else {
                    std::cout << "\e[1;33mX \e[0m";
                }
            }
        }
        std::cout << std::endl;
    }
}


void CLI::printField(GameField* playerField) {
    for (int i = playerField->getWidth() * 10; i > 0; i /= 10) {
        std::cout << " ";
    }
    for (int i = 0; i < playerField->getWidth(); ++i) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < playerField->getHeight(); ++i) {
        if (playerField->getWidth() > 9) {
            if (i < 9) {
                std::cout << i + 1 << "  ";
            } else {
                std::cout << i + 1 << " ";
            }
        } else {
            std::cout << i + 1 << " ";
        }
        for (int j = 0; j < playerField->getWidth(); ++j) {
            if (playerField->getCellState(j, i) == CellState::EMPTY) {
                std::cout << ". ";
            } else {
                std::cout << "X ";
            }

        }
        std::cout << std::endl;
    }

}

void CLI::printMessage(std::string message) {
    std::cout << message << std::endl;
}

void CLI::printError(std::string message) {
    std::cerr << message << std::endl;
}

CLI::CLI() = default;
