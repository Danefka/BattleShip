//
// Created by Даниил Гиршович on 01.12.2024.
//

#ifndef BATTLESHIPV2_0_SAVE_H
#define BATTLESHIPV2_0_SAVE_H

#include <stdexcept>
#include <string>

class SaveException : public std::runtime_error {
public:
    SaveException (const std::string& message = "save")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_SAVE_H
