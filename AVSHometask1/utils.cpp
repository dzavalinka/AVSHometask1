//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#include <cstring>
#include "utils.h"

// Генератор псевдослучайных чисел в определенном промежутке.
int randomInteger(int min, int max) {
    return std::rand() % (max - min + 1) + min;
}

// Генератор случайных слов для автоматической генерации фильмов.
char *randomWord(int len) {
    static const char alphabet[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    char *res = new char[len + 1];
    for (int i = 0; i < len; ++i) {
        res[i] = alphabet[std::rand() % (sizeof(alphabet) - 1)];
    }
    res[len] = 0;
    return res;
}

char *copyFromString(std::string &str) {
    char *result = new char[str.length() + 1];
    std::memcpy(result, str.c_str(), str.length() + 1);
    return result;
}
