//
// Created by Даниил Гиршович on 15.12.2024.
//

#ifndef BATTLESHIPV2_0_UNKNOWNCOMMANDEXCEPTION_H
#define BATTLESHIPV2_0_UNKNOWNCOMMANDEXCEPTION_H

#include <stdexcept>
#include <string>

class UnknownCommandException : public std::runtime_error {
public:
    UnknownCommandException(const std::string &message = "Unknown command")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_UNKNOWNCOMMANDEXCEPTION_H
