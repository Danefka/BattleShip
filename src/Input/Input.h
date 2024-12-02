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
#include <tuple>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#include <iosfwd>

class Input {
private:
    std::istream& is;

public:
    explicit Input(std::istream& inputStream = std::cin);
    ~Input();

    std::pair<int, int> inputSize();
    int inputValue();
    std::pair<int, int> XY();
    std::vector<int> XYOrient(int length);

    std::vector<int> shipAmount();
    bool checkSave(std::string input);
    bool checkLoad(std::string input);
    std::pair<int, int> useAbility(std::string ability);
};



#endif //BATTLESHIPV2_0_INPUT_H
