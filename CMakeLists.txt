cmake_minimum_required(VERSION 3.28)
project(BattleshipV2_0)

set(CMAKE_CXX_STANDARD 17)

# Найти nlohmann_json
find_package(nlohmann_json 3.2.0 REQUIRED)

# Основной исполняемый файл
add_executable(BattleshipV2_0 main.cpp
        src/GameLogic/Field/Cell.h
        src/GameLogic/Field/Cell.cpp
        src/GameLogic/Ship/ShipSegment.cpp
        src/GameLogic/Ship/Ship.h
        src/GameLogic/Ship/Ship.cpp
        src/GameLogic/Managers/ShipManager.h
        src/GameLogic/Managers/ShipManager.cpp
        src/GameLogic/Field/GameField.h
        src/GameLogic/Field/GameField.cpp
        src/Exceptions/AttackOutOfBoundsException.h
        src/Exceptions/InvalidShipPlacementException.h
        src/GameLogic/Attacks/IAttackable.h
        src/GameLogic/Attacks/SimpleAttack.h
        src/GameLogic/Attacks/SimpleAttack.cpp
        src/GameLogic/Attacks/DoubleAttack.h
        src/GameLogic/Attacks/DoubleAttack.cpp
        src/GameLogic/Attacks/BombingAttack.h
        src/GameLogic/Attacks/BombingAttack.cpp
        src/Utils/Random.h
        src/Exceptions/ShipSegmentHasAlreadyDestroyedException.h
        src/GameLogic/Attacks/ScannerAttack.h
        src/GameLogic/Attacks/ScannerAttack.cpp
        src/GameLogic/Managers/AttackManager.h
        src/GameLogic/Managers/AttackManager.cpp
        src/Exceptions/NoAvailableAbilityException.h
        src/GameLogic/Game.h
        src/CLI/CLI.h
        src/CLI/CLI.cpp
        src/GameLogic/Game.cpp
        src/Input/Input.h
        src/Input/Input.cpp
        src/Exceptions/SaveException.h
        src/Exceptions/LoadException.h
        src/GameLogic/State/IState.h
        src/GameLogic/State/LoadState.h
        src/GameLogic/State/PlayerTurnState.h
        src/GameLogic/State/SaveState.h
        src/GameLogic/State/NewGameState.h
        src/GameLogic/State/PlacingShipsState.h
        src/GameLogic/State/EnemyTurnState.h
        src/GameLogic/State/PlayerWonState.h
        src/GameLogic/State/NewRoundState.h
        src/GameLogic/State/EnemyWonState.h
        src/Output/Output.h
        src/GameLogic/GameController.h
        src/CLI/IGraphic.h
        src/Exceptions/UnknownCommandException.h
)

# Подключение nlohmann_json к проекту
target_link_libraries(BattleshipV2_0 PRIVATE nlohmann_json::nlohmann_json)
