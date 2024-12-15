#include "src/GameLogic/GameController.h"

int main() {
    auto* output = new Output<IGraphic>(new CLI);
    auto* input = new Input(std::cin, output);
    Game* game = new Game(input, output);
    GameController<Input, Output<IGraphic>> gameController = GameController{game, output, input};
}
