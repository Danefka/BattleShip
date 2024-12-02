//
// Created by Даниил Гиршович on 01.12.2024.
//

#ifndef BATTLESHIPV2_0_CELLISALREADYATTACKED_H
#define BATTLESHIPV2_0_CELLISALREADYATTACKED_H

#include <stdexcept>
#include <string>

class CellHasAlreadyAttacked : public std::runtime_error {
public:
    CellHasAlreadyAttacked (const std::string &message = "Cell has already attacked")
            : std::runtime_error(message) {}
};
#endif //BATTLESHIPV2_0_CELLISALREADYATTACKED_H
