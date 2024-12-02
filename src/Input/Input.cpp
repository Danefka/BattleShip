//
// Created by Даниил Гиршович on 01.12.2024.
//


#include "Input.h"
#include "../Exceptions/SaveException.h"
#include "../Exceptions/LoadException.h"


Input::Input(std::istream &inputStream) : is(inputStream) {};

std::pair<int, int> Input::XY() {
    std::cout << "Input x and y for attack" << std::endl;
    while (true) {
        int y, x;
        std::string input;
        std::getline(is, input);
        std::stringstream ss(input);
        if (int f = checkSave(input)) {
            throw SaveException();
        } else if (checkLoad(input)) {
            throw LoadException();
        }
        if (input.empty()) {
            continue;
        }
        ss >> x >> y;
        return std::make_pair(x, y);
    }
}

std::vector<int> Input::XYOrient(int length) {
    int x = 0, y = 0, orient = 0;
    std::string input;
    std::stringstream ss("");
    if (length != 1) {
        std::cout << "Place ship length:" << length
                  << ", write x and y and orientation (0 - vertical or 1 - horizontal)" << std::endl;
    } else {
        std::cout << "Place ship length:" << length
                  << ", write x and y" << std::endl;
    }
    while (true) {
        std::getline(is, input);
        ss.str(input);
        if (input.empty() || input == "\n") {
            continue;
        }
        break;
    }
    if (length != 1) {
        ss >> x >> y >> orient && ss.eof();
    } else {
        ss >> x >> y;
        orient = 0;
    }

    return {--x, --y, orient};
}

int Input::inputValue() {
    int x;
    std::string input;
    std::stringstream ss(input);
    while (true) {
        std::getline(is, input);
        ss.str(input);
        if (input.empty() || input == "\n") {
            continue;
        }
        break;
    }
    if (checkSave(input)) {
        throw SaveException();
    } else if (checkLoad(input)) {
        throw LoadException();
    }
    ss >> x;
    return x;
}

std::pair<int, int> Input::inputSize() {
    int first, second;
    while (true) {
        std::cout << "Enter size (two integers between 1 and 10): ";
        std::string input;
        std::getline(is, input);
        std::stringstream ss(input);

        if (checkSave(input)) {
            throw SaveException();
        } else if (checkLoad(input)) {
            throw LoadException();
        }

        if (ss >> first >> second && ss.eof() &&
            first > 0 && first <= 10 && second > 0 && second <= 10) {
            return {first, second};
        }
        std::cout << "Invalid input. Please enter two integers between 1 and 10.\n";
    }
}

std::vector<int> Input::shipAmount() {
    std::vector<int> *shipAmount = new std::vector<int>(4);
    int i = 0;
    while (i < 4) {
        std::cout << "How many ships with length " << 4 - i << " yow want to place" << std::endl;
        try {
            shipAmount->at(i) = inputValue();
        }
        catch (SaveException &e) {
            throw e;
        } catch (LoadException &e) {
            throw e;
        }
        if (shipAmount->at(i) > -1) {
            i++;
        }
        if(i == 4){
            int sum = 0;
            for (int j:*shipAmount) {
                sum+=j;
            }
            if (sum == 0){
                std::cout << "You have to place any ship" << std::endl;
                i=0;
            }
        }
    }
    return *shipAmount;
}

std::pair<int,int> Input::useAbility(std::string ability) {
    std::pair<int,int> xy;
    std::cout << "Do you want to use " << ability << "?" << std::endl;
    std::cout << "-1 - No, 0 - Yes " << std::endl;
    int x,y;
    std::string input;
    std::stringstream ss(input);
    while (true) {
        std::getline(is, input);
        ss.str(input);
        if (input.empty() || input == "\n") {
            continue;
        }
        break;
    }

    if (int f = checkSave(input)) {
        throw SaveException();
    } else if (checkLoad(input)) {
        throw LoadException();
    }
    ss >> xy.first >> xy.second;
    if (xy.first == 0 || xy.first == -1){
        xy.second = -1;
    }
    return xy;
}

bool Input::checkSave(std::string input) {
    return input.find("save") != std::string::npos || input.find("Save") != std::string::npos;
}

bool Input::checkLoad(std::string input) {
    return input.find("load") != std::string::npos || input.find("Load") != std::string::npos;
}

Input::~Input() = default;
