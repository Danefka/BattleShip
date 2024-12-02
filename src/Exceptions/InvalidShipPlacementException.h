//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_INVALIDSHIPPLACEMENTEXCEPTION_H
#define BATTLESHIPV2_0_INVALIDSHIPPLACEMENTEXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidShipPlacementException : public std::runtime_error {
public:
    InvalidShipPlacementException(const std::string& message = "Invalid ship placement")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_INVALIDSHIPPLACEMENTEXCEPTION_H
