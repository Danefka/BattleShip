//
// Created by Даниил Гиршович on 29->11->2024->
//

#include <unistd.h>
#include "Game.h"
#include "../Utils/Random.h"
#include "../Exceptions/NoAvailableAbilityException.h"
#include "../Exceptions/YouLoseException.h"
#include "../Exceptions/YouWonException.h"
#include "../Exceptions/LoadException.h"
#include "../Exceptions/SaveException.h"
#include "../State/PlacingShipsState.h"
#include "../State/LoadState.h"
#include "../State/NewGameState.h"
#include "../State/NewRoundState.h"
#include "../State/EnemyWonState.h"
#include "../State/PlayerWonState.h"
#include "../State/SaveState.h"
#include "../State/EnemyTurnState.h"

Game::Game() {
    state = new NewGameState();
    while (true) {
        state->state(*this);
    }
};

void Game::startNewGame() {

    input = new Input(std::cin);
    std::pair<int, int> size = {0, 0};
    try {
        size = input->inputSize();
    } catch (LoadException &e) {
        this->setState(new LoadState());
        return;
    } catch (SaveException &e) {}
    this->playerField = new GameField(size.first, size.second);
    this->graphics = new Graphics(this->playerField);
    std::vector<int> shipSizes;
    while (true) {
        try {
            shipSizes = input->shipAmount();
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                sum += (4 - i) * shipSizes.at(i);
            }
            if (sum > playerField->getWidth() * playerField->getHeight()) {
                std::cout << "\e[1;31mYou adding to many ships \e[0m" << std::endl;
                continue;
            }
            break;
        }
        catch (SaveException &e) {
        } catch (LoadException &e) {
            this->setState(new LoadState());
            return;
        }
    }
    this->playerShips = new ShipManager(
            {std::make_pair(4, shipSizes.at(0)), std::make_pair(3, shipSizes.at(1)),
             std::make_pair(2, shipSizes.at(2)), std::make_pair(1, shipSizes.at(3))});
    this->playersAbilities = new AttackManager();
    this->setState(new PlacingShipsState());
}

void Game::startGameFromFile() {
    this->playerField = new GameField();
    this->graphics = new Graphics();
    this->playerShips = new ShipManager();
    this->playersAbilities = new AttackManager();
    this->enemyField = new GameField();
    this->enemyShips = new ShipManager();
    load();
    std::cout << "starting..." << std::endl;
    this->setState(new PlayerTurnState());
}

void Game::placingShips() {
    std::cout << "Place your ships" << std::endl;
    for (Ship *ship: playerShips->getShips()) {
        bool shipPlaced = false;
        graphics->startGamePrint();
        while (!shipPlaced) {
            try {
                std::vector<int> XYOrient = input->XYOrient(ship->getLength());
                playerField->placeShip(XYOrient.at(0), XYOrient.at(1), ship, XYOrient.at(2));
            } catch (const std::invalid_argument &e) {
                std::cerr << e.what() << std::endl;
                continue;
            } catch (const InvalidShipPlacementException &e) {
                std::cerr << e.what() << std::endl;
                continue;
            } catch (LoadException &e) {
                this->setState(new LoadState());
                return;
            } catch (SaveException &e) {
                std::cout << "nothing to save" << std::endl;
                continue;
            }
            shipPlaced = true;
        }
    }

    std::cout << "starting..." << std::endl;

    this->setState(new NewRoundState());

}


void Game::newRound() {
    this->enemyField = new GameField(playerField->getWidth(), playerField->getHeight());
    std::vector<int> amountShips = playerShips->amountShips();
    this->enemyShips = new ShipManager(
            {std::make_pair(4, amountShips.at(0)), std::make_pair(3, amountShips.at(1)),
             std::make_pair(2, amountShips.at(2)), std::make_pair(1, amountShips.at(3))});
    graphics->setEnemyField(enemyField);
    for (Ship *ship: enemyShips->getShips()) {
        bool shipPlaced = false;
        while (!shipPlaced) {
            int x = Random::getRandomNumber(0, enemyField->getWidth() - 1);
            int y = Random::getRandomNumber(0, enemyField->getHeight() - 1);
            if (enemyField->getCellState(x, y) == CellState::SHIP) { continue; }
            int horizontal = Random::getRandomNumber(0, 1);
            try {
                enemyField->placeShip(x, y, ship, horizontal);
            } catch (const std::runtime_error &e) {
                continue;
            }

            shipPlaced = true;
        }
    }

    setState(new PlayerTurnState());
}

void Game::playerTurn() {
    graphics->print();
    bool oneMoreTurn = false;
    while (true) {
        if (enemyShips->Lose()) {
            this->setState(new PlayerWonState());
            return;
        }
        IAttackable *attack = nullptr;
        std::pair<int, int> useAbility = {-1, -1};
        bool skipXY = false;
        bool skipAbility = false;
        if (oneMoreTurn) {
            graphics->print();
        }
        oneMoreTurn = false;
        try {
            std::string ability = playersAbilities->peek();
            try {
                useAbility = input->useAbility(ability);
            } catch (SaveException &e) {
                this->setState(new SaveState());
                return;
            } catch (LoadException &e) {
                this->setState(new LoadState());
                return;
            }
            if (useAbility.first == 0) {
                if (ability == "Bombing Attack") {
                    skipXY = true;
                }
                attack = playersAbilities->getAbility();
            } else if (useAbility.first != -1) {
                skipAbility = true;
            }
        } catch (const NoAvailableAbilityException &e) {
            std::cerr << e.what() << std::endl;
        }
        if (useAbility.first != 0) {
            attack = new SimpleAttack();
        }

        if (skipXY) {
            try {
                if (attack != nullptr) {
                    attack->setShipManager(enemyShips);
                    attack->attack(1, 1, enemyField);
                    oneMoreTurn = true;
                }
                continue;
            } catch (const std::runtime_error &e) {
                std::cerr << e.what() << std::endl;
                continue;
            }
        }
        std::pair<int, int> xy;
        if (skipAbility) {
            xy = useAbility;
        } else {
            try {
                xy = input->XY();
            } catch (SaveException &e) {
                this->setState(new SaveState());
                return;
            } catch (LoadException &e) {
                this->setState(new LoadState());
                return;
            }
        }

        xy.first--;
        xy.second--;
        try {
            enemyField->checkCoordinate(xy.first, xy.second);
        } catch (const AttackOutOfBoundsException &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }


        int amount = enemyShips->amountOfSurvivingShips();
        try {
            if (attack != nullptr) {
                oneMoreTurn = attack->attack(xy.first, xy.second, enemyField);
            }
        } catch (const std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }


        if (amount != enemyShips->amountOfSurvivingShips()) {
            playersAbilities->addRandomAbility();
        }

        if (oneMoreTurn) {
            continue;
        }
        this->setState(new EnemyTurnState());
        break;
    }
}

void Game::enemyTurn() {
    SimpleAttack enemyAttack = SimpleAttack();
    bool oneMoreTurn = false;
    for (int i = 0; i < 10; ++i) {
        if (playerShips->Lose()) {
            setState(new EnemyWonState());
            return;
        }
        int x = Random::getRandomNumber(0, playerField->getWidth() - 1);
        int y = Random::getRandomNumber(0, playerField->getWidth() - 1);
        if (oneMoreTurn) {
            graphics->print();
        }
        oneMoreTurn = false;
        try {
            oneMoreTurn = enemyAttack.attack(x, y, playerField);
        } catch (std::runtime_error &e) {
            continue;
        }
        printf("\e[1;31menemy attack cell %d %d \e[0m", x + 1, y + 1);
        if (oneMoreTurn) {
            continue;
        }
        setState(new PlayerTurnState());
        return;
    }
    for (int i = 0; i < enemyField->getWidth(); ++i) {
        for (int j = 0; j < enemyField->getHeight(); ++j) {
            try {
                oneMoreTurn = enemyAttack.attack(i, j, playerField);
                if (playerShips->Lose()) {
                    setState(new EnemyWonState());
                    return;
                }
            } catch (std::runtime_error &e) {
                continue;
            }
            printf("\e[1;31menemy attack cell %d %d \e[0m", i + 1, j + 1);
            if (oneMoreTurn) {
                continue;
            }
            setState(new PlayerTurnState());
            return;
        }
    }
}

nlohmann::json Game::toJson() const {
    std::unordered_map<int, ShipSegment *> playerSegmentMap;
    for (Ship *ship: playerShips->getShips()) {
        for (int i = 0; i < ship->getLength(); i++) {
            playerSegmentMap[ship->getSegment(i).getId()] = &ship->getSegment(i);
        }
    }
    nlohmann::json j;
    nlohmann::json playerSegmentJson = nlohmann::json::array();
    for (const auto &segmentPair: playerSegmentMap) {
        playerSegmentJson.push_back(segmentPair.second->toJson());  // Сериализация каждого сегмента
    }

    std::unordered_map<int, ShipSegment *> enemySegmentMap;
    for (Ship *ship: enemyShips->getShips()) {
        for (int i = 0; i < ship->getLength(); i++) {
            enemySegmentMap[ship->getSegment(i).getId()] = &ship->getSegment(i);
        }
    }

    nlohmann::json enemySegmentsJson = nlohmann::json::array();
    for (const auto &segmentPair: enemySegmentMap) {
        enemySegmentsJson.push_back(segmentPair.second->toJson());  // Сериализация каждого сегмента
    }
    j["playerSegments"] = playerSegmentJson;
    j["playerField"] = playerField->toJson();
    j["playerShips"] = playerShips->toJson();
    j["playerAbilities"] = playersAbilities->toJson();
    j["enemySegments"] = enemySegmentsJson;
    j["enemyField"] = enemyField->toJson();
    j["enemyShips"] = enemyShips->toJson();
    enemySegmentsJson.clear();
    playerSegmentJson.clear();
    return j;
}

void Game::from_json(const nlohmann::json &j) {
    std::unordered_map<int, ShipSegment *> playerSegmentMap;
    const auto &playerSegmentJson = j.at("playerSegments");
    for (const auto &segmentJson: playerSegmentJson) {
        ShipSegment *segment = new ShipSegment();
        *segment = ShipSegment::fromJson(segmentJson);
        playerSegmentMap[segment->getId()] = segment;  // Восстановление по ID
    }
    std::unordered_map<int, ShipSegment *> enemySegmentMap;
    const auto &enemySegmentsJson = j.at("enemySegments");
    for (const auto &segmentJson: enemySegmentsJson) {
        ShipSegment *segment = new ShipSegment();
        *segment = ShipSegment::fromJson(segmentJson);
        enemySegmentMap[segment->getId()] = segment;  // Восстановление по ID
    }

    playerField->fromJson(j.at("playerField"), playerSegmentMap);
    playerShips->fromJson(j.at("playerShips"), playerSegmentMap);
    playersAbilities->fromJson(j.at("playerAbilities"));
    enemyField->fromJson(j.at("enemyField"), enemySegmentMap);
    enemyShips->fromJson(j.at("enemyShips"), enemySegmentMap);
    this->graphics = new Graphics(playerField);
    this->graphics->setEnemyField(enemyField);
    this->input = new Input(std::cin);
}

void Game::save() {
    nlohmann::json j = this->toJson();

    std::ofstream outFile("Game.json");
    if (!outFile.is_open()) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    outFile << j;
    outFile.close();
}

void Game::load() {
    std::ifstream inFile("Game.json");
    if (!inFile.is_open()) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    nlohmann::json j;
    inFile >> j;  // Загружаем данные из файла в JSON
    inFile.close();  // Закрываем файл
    this->from_json(j);
}

void Game::setState(IState *state) {
    Game::state = state;
}

void Game::youWon() {
    std::cout << "Starting a new round..." << std::endl;
    sleep(2);
    this->setState(new NewRoundState());
}

void Game::youLose() {
    std::cout << "Starting a new game..." << std::endl;
    sleep(2);
    this->setState(new NewGameState());
}



Game::~Game() = default;

