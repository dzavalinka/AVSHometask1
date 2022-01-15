//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#include <cstring>
#include "documentary.h"
#include "utils.h"

void In(documentary &documentary, std::ifstream &stream) {
    std::string name;
    stream >> name >> documentary.year >> documentary.duration;
    // Дополнительная проверка на ввод
    if (documentary.year < 1950 || documentary.year > 10000) {
        documentary.year = randomInteger(1950, 2021);
    }
    if (documentary.duration < 0 || documentary.duration > INT32_MAX) {
        documentary.duration = randomInteger(1, 10);
    }
    documentary.name = copyFromString(name);
}

void InRandom(documentary &documentary) {
    documentary.name = randomWord(randomInteger(5, 10));
    documentary.year = randomInteger(1950, 2021);
    documentary.duration = randomInteger(1, 10);
}

void Out(documentary &documentary, std::ofstream &stream) {
    stream << "Documentary: name = " << documentary.name << ", year = " << documentary.year << ", duration = "
           << documentary.duration
           << ", year / name.len(): " << Function(documentary) << "\n";
}

double Function(documentary &documentary) {
    return static_cast<double>(documentary.year) / static_cast<double>(strlen(documentary.name));
}
