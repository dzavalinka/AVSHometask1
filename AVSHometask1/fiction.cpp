//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#include <cstring>
#include "fiction.h"
#include "utils.h"

void In(fiction &fiction, std::ifstream &stream) {
    std::string name;
    std::string director;

    stream >> name >> fiction.year >> director;
    // Дополнительная проверка на ввод.
    if (fiction.year < 1950 || fiction.year > 10000) {
        fiction.year = randomInteger(1950, 2021);
    }
    fiction.name = copyFromString(name);
    fiction.director = copyFromString(director);
}

void InRandom(fiction &fiction) {
    fiction.name = randomWord(randomInteger(5, 10));
    fiction.year = randomInteger(1950, 2021);
    fiction.director = randomWord(randomInteger(10, 20));
}

void Out(fiction &fiction, std::ofstream &stream) {
    stream << "Fiction film: name - " << fiction.name << ", year of release - " << fiction.year << ", director - "
           << fiction.director << "\n";;
}

double Function(fiction &f) {
    return static_cast<double>(f.year) / static_cast<double>(strlen(f.name));
}
