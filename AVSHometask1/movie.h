//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#ifndef AVSHOMETASK1_MOVIE_H
#define AVSHOMETASK1_MOVIE_H

#include "fiction.h"
#include "cartoon.h"
#include "documentary.h"

struct movie {
    enum type {
        FICTION, CARTOON, DOCUMENTARY
    };
    type type;
    union {
        fiction fic;
        cartoon car;
        documentary doc;
    };
};

// Ввод фильма из потока ввода.
movie *In(std::ifstream &stream);

// Ввод случайно сгенерированного фильма из потока ввода.
movie *InRandom();

// Вывод фильма из потока вывода.
void Out(movie &movie, std::ofstream &stream);

// Вывод функции общей для всех альтернатив.
double Function(movie &m);


#endif //AVSHOMETASK1_MOVIE_H
