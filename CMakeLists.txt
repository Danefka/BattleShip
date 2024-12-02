cmake_minimum_required(VERSION 3.28)
project(BattleshipV2_0)

set(CMAKE_CXX_STANDARD 17)

# Найти nlohmann_json
find_package(nlohmann_json 3.2.0 REQUIRED)

# Основной исполняемый файл
add_executable(BattleshipV2_0 main.cpp
        src/Field/Cell.h
        src/Field/Cell.cpp
        src/Ship/ShipSegment.cpp
        src/Ship/Ship.h
        src/Ship/Ship.cpp
        src/Managers/ShipManager.h
        src/Managers/ShipManager.cpp
        src/Field/GameField.h
        src/Field/GameField.cpp
        src/Exceptions/AttackOutOfBoundsException.h
        src/Exceptions/InvalidShipPlacementException.h
        src/Attacks/IAttackable.h
        src/Attacks/SimpleAttack.h
        src/Attacks/SimpleAttack.cpp
        src/Attacks/DoubleAttack.h
        src/Attacks/DoubleAttack.cpp
        src/Attacks/BombingAttack.h
        src/Attacks/BombingAttack.cpp
        src/Utils/Random.h
        src/Exceptions/ShipSegmentHasAlreadyDestroyedException.h
        src/Attacks/ScannerAttack.h
        src/Attacks/ScannerAttack.cpp
        src/Managers/AttackManager.h
        src/Managers/AttackManager.cpp
        src/Exceptions/NoAvailableAbilityException.h
        src/GameLogic/Game.h
        src/Graphics/Graphics.h
        src/Graphics/Graphics.cpp
        src/GameLogic/Game.cpp
        src/Input/Input.h
        src/Input/Input.cpp
        src/Exceptions/SaveException.h
        src/Exceptions/LoadException.h
        src/State/IState.h
        src/State/LoadState.h
        src/State/PlayerTurnState.h
        src/State/SaveState.h
        src/State/NewGameState.h
        src/State/PlacingShipsState.h
        src/State/EnemyTurnState.h
        src/State/PlayerWonState.h
        src/State/NewRoundState.h
        src/State/EnemyWonState.h
)

# Подключение nlohmann_json к проекту
target_link_libraries(BattleshipV2_0 PRIVATE nlohmann_json::nlohmann_json)
