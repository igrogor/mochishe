// Вариант 12
// Построить класс для работы с журналами: название (динамическое
// выделение памяти для названия), количество выпусков в год, тираж.
// Класс должен обеспечивать простейшие функции для работы с
// данными класса: изменение значений, вывод значений, сложение двух
// объектов класса.

#include "../HeaderFiles/headers.h"

int main() {
    Journal journal[N];

    for (int i = 0; i < N; i++) {
        journal[i].set_year(1835 + i);
        journal[i].set_name("PlayBoy");
        journal[i].set_circulation(12000 + i);
    }

    for (int i = 0; i < N; i++) {
        journal[i].Print();
    }

    return 0;
}
