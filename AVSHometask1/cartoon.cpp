//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#include <cstring>
#include "cartoon.h"
#include "utils.h"

void In(cartoon &cartoon, std::ifstream &stream) {
    std::string name;
    stream >> name >> cartoon.year;
    // Дополнительная проверка на ввод
    if (cartoon.year < 1950 || cartoon.year > 10000) {
        cartoon.year = randomInteger(1950, 2022);
    }
    cartoon.name = copyFromString(name);
    char type[100];
    stream >> type;
    if (!strcmp(type, "painted")) {
        cartoon.t = cartoon::DRAW;
    } else if (!strcmp(type, "puppet")) {
        cartoon.t = cartoon::PUPPET;
    } else if (!strcmp(type, "plasticine")) {
        cartoon.t = cartoon::PLASTICINE;
    } else {
        cartoon.t = cartoon::DRAW;
    }
}

void InRandom(cartoon &cartoon) {
    cartoon.name = randomWord(randomInteger(5, 10));
    cartoon.year = randomInteger(1950, 2021);
    int type = randomInteger(0, 2);
    cartoon.t = static_cast<cartoon::type>(type);
}

void Out(cartoon &cartoon, std::ofstream &stream) {
    std::string type;
    switch (cartoon.t) {
        case cartoon::DRAW:
            type = "painted";
            break;
        case cartoon::PUPPET:
            type = "puppet";
            break;
        case cartoon::PLASTICINE:
            type = "plasticine";
            break;
    }
    stream << "Animation film: name - " << cartoon.name << ", year of release - " << cartoon.year << ", animation type - " << type << "\n";
}

double Function(cartoon &c) {
    return static_cast<double>(c.year) / static_cast<double>(strlen(c.name));
}
