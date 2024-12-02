//
// Created by Даниил Гиршович on 29.11.2024.
//

#include "Graphics.h"

Graphics::Graphics(GameField *gameField) {
    this->playerField = gameField;
    this->enemyField = nullptr;
}

void Graphics::print() {
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


void Graphics::setEnemyField(GameField *enemyField) {
    Graphics::enemyField = enemyField;
}

void Graphics::startGamePrint() {
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

Graphics::Graphics() = default;
