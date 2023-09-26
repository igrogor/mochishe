// Вариант 12
// Построить класс для работы с журналами: название (динамическое
// выделение памяти для названия), количество выпусков в год, тираж.
// Класс должен обеспечивать простейшие функции для работы с
// данными класса: изменение значений, вывод значений, сложение двух
// объектов класса.

#include <iostream>

class Journal {
   public:
    char* name;
    int year;
    int circulation;
    void print() { std::cout << ' ' << name << ' ' << year  << ' ' << circulation << std::endl; }
};

int main() {
    Journal journal;
    journal.year = 1912;
    journal.name = "match";
    journal.circulation = 100;
    journal.print();

    return 0;
}