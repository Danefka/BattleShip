//
// Created by Даниил Гиршович on 01.12.2024.
//

#ifndef BATTLESHIPV2_0_INPUT_H
#define BATTLESHIPV2_0_INPUT_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <fstream>
#include "../Exceptions/UnknownCommandException.h"
#include "../CLI/IGraphic.h"
#include "../Output/Output.h"

enum Command{
    NEW_GAME,
    START_GAME,
    SAVE,
    LOAD,
    QUIT,
    HELP,
    SILENT
};

class Input {
private:
    Output<IGraphic> *output;
    std::istream& is;
    bool trustFile;
public:
    Input(std::istream &is, Output<IGraphic> *output);
    ~Input();

    std::pair<int, int> inputSize();
    int inputValue();
    std::pair<int, int> XY();
    std::vector<int> XYOrient(int length);

    std::vector<int> shipAmount();
    bool checkSave(std::string input);
    bool checkLoad(std::string input);
    std::pair<int, int> useAbility(std::string ability);
    Command inputCommand();

    Command standardCommand(std::string str);
    Command stringToCommand(const std::string& str);

    void checkQuit(std::string input);
    bool validateEmptyKeysForJsonFile(const std::string& filename);

    bool validateDuplicateForJsonFile(const std::string &filename);
};



#endif //BATTLESHIPV2_0_INPUT_H
