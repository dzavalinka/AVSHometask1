//
// Created by Daniil Zavalinskii on 13.01.2022.
//

#include "container.h"

void Init(container &c) {
    c.len = 0;
}

void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

void In(container &c, std::ifstream &stream) {
    while (!stream.eof() && stream.good()) {
        if ((c.cont[c.len] = In(stream)) != nullptr) {
            c.len++;
        }
    }
}

void InRandom(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRandom()) != nullptr) {
            c.len++;
        }
    }
}

void Out(container &c, std::ofstream &stream) {
    stream << "Container contains " << c.len << " elements." << std::endl;
    for (int i = 0; i < c.len; i++) {
        stream << i << ": ";
        Out(*(c.cont[i]), stream);
    }
}

void InsertionSort(container &c) {
    for (int i = 0; i < c.len; ++i) {
        movie key = *c.cont[i];
        int j = i - 1;
        while (Function(key) > Function(*c.cont[j]) && j >= 0) {
            c.cont[j + 1] = c.cont[j];
            --j;
        }
        c.cont[j + 1] = &key;
    }
}
