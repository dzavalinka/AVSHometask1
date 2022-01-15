//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#ifndef AVSHOMETASK1_CONTAINER_H
#define AVSHOMETASK1_CONTAINER_H


#include "movie.h"

struct container {
    enum {
        max_len = 10000
    };
    int len;
    movie *cont[max_len];
};

// Инициализирует пустой контейнер.
void Init(container &c);

// Очистка контейнера.
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока.
void In(container &c, std::ifstream &stream);

// Случайный ввод содержимого контейнера.
void InRandom(container &c, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(container &c, std::ofstream &stream);

// Сортировка элементов контейнера согласно условию.
void InsertionSort(container &c);


#endif //AVSHOMETASK1_CONTAINER_H
