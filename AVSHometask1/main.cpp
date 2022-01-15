#include <iostream>
#include <cstdlib>
#include <ctime>   // для функции time()
#include <cstring>
#include "utils.h"
#include "container.h"

void first_error_message() {
    std::cout << "incorrect command line!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void second_error_message() {
    std::cout << "incorrect qualifier value!\n"
                 "  Waited:\n"
                 "     command -f infile outfile01 outfile02\n"
                 "  Or:\n"
                 "     command -n number outfile01 outfile02\n";
}

void third_error_message(int size) {
    std::cout << "incorrect number of items = "
              << size
              << ". Set 0 < number <= 10000\n";
}

int main(int argc, char *argv[]) {

    if (argc != 5) {
        first_error_message();
        return 1;
    }

    std::cout << "Start" << std::endl;
    container container{};
    Init(container);

    if (!strcmp(argv[1], "file")) {
        std::ifstream stream(argv[2]);
        // Проверка на существование файла, если файл не существует, выбросится предупреждение.
        if (stream.is_open())
            In(container, stream);
        else {
            std::cout << "File doesn't exist!" << "\n";
            return 1;
        }
    } else if (!strcmp(argv[1], "random")) {
        auto size = std::atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            third_error_message(size);
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел.
        InRandom(container, size);
    } else {
        second_error_message();
        return 2;
    }

    std::ofstream of_stream(argv[3]);
    of_stream << "Input container:\n";
    Out(container, of_stream);

    std::ofstream out_stream(argv[4]);
    InsertionSort(container);
    out_stream << "Sorted container:\n";
    Out(container, out_stream);
    Clear(container);
    std::cout << "Stop" << std::endl;
    return 0;
}