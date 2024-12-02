//
// Created by Даниил Гиршович on 10.11.2024.
//

#ifndef BATTLESHIPV2_0_RANDOM_H
#define BATTLESHIPV2_0_RANDOM_H

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "random"
class Random{
public:
    static int getRandomNumber(int min, int max)
        {
            static int count;
            std::srand(std::time(nullptr));
            unsigned int num = min + std::rand() % (max - min + 1);
            count++;
            return (num + count)*(random() + count)%(max - min + 1);
        }};
#endif //BATTLESHIPV2_0_RANDOM_H
