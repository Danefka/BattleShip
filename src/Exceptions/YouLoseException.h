//
// Created by Даниил Гиршович on 29.11.2024.
//

#ifndef BATTLESHIPV2_0_YOULOSEEXCEPTION_H
#define BATTLESHIPV2_0_YOULOSEEXCEPTION_H

#include <stdexcept>
#include <string>

class YouLoseException : public std::runtime_error {
public:
    YouLoseException(const std::string& message = "Game over")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_YOULOSEEXCEPTION_H
