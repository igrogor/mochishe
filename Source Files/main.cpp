// Вариант 12
// Построить класс для работы с журналами: название (динамическое
// выделение памяти для названия), количество выпусков в год, тираж.
// Класс должен обеспечивать простейшие функции для работы с
// данными класса: изменение значений, вывод значений, сложение двух
// объектов класса.

#include "../HeaderFiles/headers.h"




int main() {
    Journal journal[N];

    for(int i = 0; i < N; i++){
        journal[i].year = 1912 + i;
        strcpy(journal[i].name,"match");
        //journal[i].name = "match";
        journal[i].circulation = 100 + i;
    }

    journal[1].Print(journal);

    return 0;
}



