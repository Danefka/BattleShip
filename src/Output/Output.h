//
// Created by Даниил Гиршович on 15.12.2024.
//

#ifndef BATTLESHIPV2_0_OUTPUT_H
#define BATTLESHIPV2_0_OUTPUT_H

#include "string"
#include <fstream>
#include "unordered_map"
#include "../GameLogic/Field/GameField.h"

template<typename OutputClass>
class Output {
private:
    OutputClass *outputClass;
public:
    explicit Output(OutputClass *outputClass) : outputClass(outputClass) {}
    ~Output() = default;


    void printMessage(std::string message);
    void printError(std::string message);
    void printFields(GameField *playerField, GameField *enemyField);
    void printField(GameField *playerField);

    void help();
    void standartHelp();
};

template<typename OutputClass>
void Output<OutputClass>::printError(std::string message) {
    outputClass->printError(message);
}

template<typename OutputClass>
void Output<OutputClass>::standartHelp() {
    outputClass->printMessage("h - help");
    outputClass->printMessage("s - save");
    outputClass->printMessage("l - load");
    outputClass->printMessage("b - start game");
    outputClass->printMessage("n - create new game");
    outputClass->printMessage("q - quit");
}

template<typename OutputClass>
void Output<OutputClass>::help() {
    nlohmann::json data;
    std::ifstream inFile("commands.json");

    if (!inFile.is_open()) {
        outputClass->printMessage("Available commands:");
        standartHelp();
        return;
    }

    inFile >> data;
    inFile.close();

    std::unordered_map<std::string, std::vector<std::string>> commandMap;

    for (const auto &[shortCommand, fullCommand] : data.items()) {
        commandMap[fullCommand].emplace_back(shortCommand);
    }

    outputClass->printMessage("Available commands:");
    for (const auto &[fullCommand, shortCommands] : commandMap) {
        std::string message = fullCommand + ": ";
        for (const auto &shortCommand : shortCommands) {
            message += "\"" +  shortCommand + "\" ";
        }
        outputClass->printMessage(message);
    }
}


template<typename OutputClass>
void Output<OutputClass>::printField(GameField *playerField) {
    outputClass->printField(playerField);
}

template<typename OutputClass>
void Output<OutputClass>::printFields(GameField *playerField, GameField *enemyField) {
    outputClass->printFields(playerField, enemyField);
}

template<typename OutputClass>
void Output<OutputClass>::printMessage(std::string message) {
    outputClass->printMessage(message);
}


#endif //BATTLESHIPV2_0_OUTPUT_H
