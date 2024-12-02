//
// Created by Даниил Гиршович on 01.12.2024.
//

#ifndef BATTLESHIPV2_0_LOADEXCEPTION_H
#define BATTLESHIPV2_0_LOADEXCEPTION_H

#include <stdexcept>
#include <string>

class LoadException : public std::runtime_error {
public:
    LoadException (const std::string& message = "load")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_LOADEXCEPTION_H
