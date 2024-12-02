//
// Created by Даниил Гиршович on 29.11.2024.
//

#ifndef BATTLESHIPV2_0_YOUWONEXCEPTION_H
#define BATTLESHIPV2_0_YOUWONEXCEPTION_H

#include <stdexcept>
#include <string>

class YouWonException : public std::runtime_error {
public:
    YouWonException(const std::string& message = "Congratulates, you won")
            : std::runtime_error(message) {}
};
#endif //BATTLESHIPV2_0_YOUWONEXCEPTION_H
