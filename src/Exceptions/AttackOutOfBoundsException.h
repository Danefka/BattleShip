//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_ATTACKOUTOFBOUNDSEXCEPTION_H
#define BATTLESHIPV2_0_ATTACKOUTOFBOUNDSEXCEPTION_H

#include <stdexcept>
#include <string>

class AttackOutOfBoundsException : public std::runtime_error {
private:
    std::string message;
public:
    AttackOutOfBoundsException(const std::string &message = "Attack out of bounds")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_ATTACKOUTOFBOUNDSEXCEPTION_H
