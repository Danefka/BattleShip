//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_NOAVAILABLEABILITYEXCEPTION_H
#define BATTLESHIPV2_0_NOAVAILABLEABILITYEXCEPTION_H

#include <stdexcept>
#include <string>

class NoAvailableAbilityException : public std::runtime_error {
public:
    NoAvailableAbilityException (const std::string& message = "You haven't any abilities available")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_NOAVAILABLEABILITYEXCEPTION_H
