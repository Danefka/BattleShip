//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_SHIPSEGMENTHASALREADYDESTROYEDEXCEPTION_H
#define BATTLESHIPV2_0_SHIPSEGMENTHASALREADYDESTROYEDEXCEPTION_H

#include <stdexcept>
#include <string>

class ShipSegmentHasAlreadyDestroyedException : public std::runtime_error {
public:
    ShipSegmentHasAlreadyDestroyedException (const std::string &message = "Ship Segment has already destroyed")
            : std::runtime_error(message) {}
};

#endif //BATTLESHIPV2_0_SHIPSEGMENTHASALREADYDESTROYEDEXCEPTION_H
