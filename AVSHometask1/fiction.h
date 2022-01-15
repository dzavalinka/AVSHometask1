//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#ifndef AVSHOMETASK1_FICTION_H
#define AVSHOMETASK1_FICTION_H


#include <fstream>
#include <string>

// Структура научного фильма.
struct fiction {
    char *name;
    int year;

    char *director;
};

// Ввод игрового фильма из потока ввода.
void In(fiction &fiction, std::ifstream &stream);

// Ввод случайно сгенерированного игрового фильма из потока ввода.
void InRandom(fiction &fiction);

// Вывод игрового фильма из потока вывода.
void Out(fiction &fiction, std::ofstream &stream);

// Вывод функции общей для всех альтернатив.
double Function(fiction &f);



#endif //AVSHOMETASK1_FICTION_H
