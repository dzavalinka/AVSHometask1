//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#ifndef AVSHOMETASK1_DOCUMENTARY_H
#define AVSHOMETASK1_DOCUMENTARY_H


#include <fstream>
#include <string>

// Структура Документального класса.
struct documentary {
    char *name;
    int year;
    int duration;
};

// Ввод документального фильма из потока ввода.
void In(documentary &documentary, std::ifstream &stream);

// Вывод случайно сгенерированного документального фильма из потока ввода.
void InRandom(documentary &documentary);

// Вывод документального фильма из потока вывода.
void Out(documentary &documentary, std::ofstream &stream);

// Вывод функции общей для всех альтернатив.
double Function(documentary &documentary);


#endif //AVSHOMETASK1_DOCUMENTARY_H
