//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#ifndef AVSHOMETASK1_CARTOON_H
#define AVSHOMETASK1_CARTOON_H


#include <fstream>
#include <string>

struct cartoon {
    char *name;
    int year;
    enum type {
        DRAW, PUPPET, PLASTICINE
    };
    type t;
};

// ввод анимационного фильма из потока ввода
void In(cartoon &cartoon, std::ifstream &stream);

// ввод случайно сгенерированного анимационного фильма из потока ввода
void InRandom(cartoon &cartoon);

// ввод анимационного фильма из потока ввода
void Out(cartoon &cartoon, std::ofstream &stream);

// вычисление признака альтернативы
double Function(cartoon &c);



#endif //AVSHOMETASK1_CARTOON_H
