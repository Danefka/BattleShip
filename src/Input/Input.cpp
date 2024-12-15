//
// Created by Даниил Гиршович on 01.12.2024.
//


#include <nlohmann/json.hpp>
#include "Input.h"
#include "../Exceptions/SaveException.h"
#include "../Exceptions/LoadException.h"
#include "unordered_set"
#include <regex>



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
        output->printMessage("Enter size (two integers between 1 and 10): ");
        std::string input;
        std::getline(is, input);
        std::stringstream ss(input);

        if (checkSave(input)) {
            output->printError("nothing to save");
            continue;
        } else if (checkLoad(input)) {
            throw LoadException();
        }
        checkQuit(input);

        checkQuit(input);

        if (ss >> first >> second && ss.eof() &&
            first > 0 && first <= 10 && second > 0 && second <= 10) {
            return {first, second};
        }
        output->printError("Invalid input. Please enter two integers between 1 and 10.");
    }
}

std::vector<int> Input::shipAmount() {
    std::vector<int> *shipAmount = new std::vector<int>(4);
    int i = 0;
    while (i < 4) {
        output->printMessage("How many ships with length " + std::to_string(4 - i) + " yow want to place");
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
        if (i == 4) {
            int sum = 0;
            for (int j: *shipAmount) {
                sum += j;
            }
            if (sum == 0) {
                output->printError("You have to place any ship");
                i = 0;
            }
        }
    }
    return *shipAmount;
}

std::pair<int, int> Input::useAbility(std::string ability) {
    std::pair<int, int> xy;
    output->printMessage("Do you want to use " + ability + "?");
    output->printMessage("-1 - No, 0 - Yes ");
    int x, y;
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
    checkQuit(input);

    ss >> xy.first >> xy.second;
    if (xy.first == 0 || xy.first == -1) {
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

void Input::checkQuit(std::string input) {
    if (input.find("quit") != std::string::npos || input.find("Quit") != std::string::npos) {
        exit(0);
    }
}


Input::Input(std::istream &is, Output<IGraphic> *output) : is(is), output(output),
                                                           trustFile(validateEmptyKeysForJsonFile("commands.json") and
                                                                             validateDuplicateForJsonFile("commands.json")) {}

Input::~Input() = default;

Command Input::standardCommand(std::string str) {
    if (str == "b") { return START_GAME; }
    if (str == "n") { return NEW_GAME; }
    if (str == "s") { return SAVE; }
    if (str == "l") { return LOAD; }
    if (str == "q") { return QUIT; }
    if (str == "h") { return HELP; }
    if (str == ".") { return SILENT; }
    throw UnknownCommandException(str);
}

Command Input::inputCommand() {
    std::string input;
    nlohmann::json data;
    std::ifstream inFile("commands.json");
    if (!inFile.is_open() || !trustFile) {
        output->printMessage("enter standard command");
        while (true) {
            std::getline(is, input);
            try {
                Command command = standardCommand(input);
                return command;
            } catch (UnknownCommandException &e) {
                std::ostringstream oss;
                oss << e.what();
                output->printError("Command " + oss.str() + " is not define");
            }
        }
    }
    inFile >> data;
    inFile.close();
    while (true) {
        output->printMessage("enter command");
        std::getline(is, input);
        try {
            if (data.contains(input)) {
                std::string str = data[input];
                Command command = stringToCommand(str);
                return command;
            }
            throw UnknownCommandException(input);
        } catch (UnknownCommandException &e) {
            std::ostringstream oss;
            oss << e.what();
            output->printError("Command " + oss.str() + " is not define");
        }
    }
}

Command Input::stringToCommand(const std::string &str) {
    if (str == "NEW_GAME") return Command::NEW_GAME;
    if (str == "START_GAME") return Command::START_GAME;
    if (str == "SAVE") return Command::SAVE;
    if (str == "LOAD") return Command::LOAD;
    if (str == "QUIT") return Command::QUIT;
    if (str == "HELP") return Command::HELP;
    if (str == "SILENT") return Command::SILENT;
    throw UnknownCommandException();
}


bool Input::validateEmptyKeysForJsonFile(const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        output->printError("Can't open the file " + filename);
        return false;
    }

    nlohmann::json data;
    inFile >> data;

    for (const auto &[key, value]: data.items()) {
        if (key.empty()) {
            output->printError("Error, file contain empty key.");
            return false;
        }
    }
    return true;
}

bool Input::validateDuplicateForJsonFile(const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        output->printError("Can't open the file " + filename);
        return false;
    }

    std::string jsonContent((std::istreambuf_iterator<char>(inFile)),
                            std::istreambuf_iterator<char>());

    std::unordered_set<std::string> seenKeys;

    std::regex keyRegex("\"([^\"]+)\":");
    std::smatch match;

    std::string::const_iterator searchStart(jsonContent.cbegin());
    while (std::regex_search(searchStart, jsonContent.cend(), match, keyRegex)) {
        std::string key = match[1];
        if (seenKeys.count(key)) {
            output->printError("Error, key \"" + key + "\" duplicates.");
            return false;
        }
        seenKeys.insert(key);
        searchStart = match.suffix().first;
    }

    return true;
}