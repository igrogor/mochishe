// Вариант 12
// Построить класс для работы с журналами: название (динамическое
// выделение памяти для названия), количество выпусков в год, тираж.
// Класс должен обеспечивать простейшие функции для работы с
// данными класса: изменение значений, вывод значений, сложение двух
// объектов класса.

#include "../HeaderFiles/headers.h"

void main_window();

int main() {
    main_window();

    return 0;
}

void main_window() {
    Journal journal[N];

    for (int i = 0; i < N; i++) {
        journal[i].set_year(1835 + i);
        journal[i].set_name("PlayBoy");
        journal[i].set_circulation(12000 + i);
    }

    int i = 5;
    while ((i != 0)) {
        cout << "intput num :\n0 - end\n1 - print\n2 - sum journal\n3 - edit journal\n";
        cin >> i;
        switch (i) {
            case 0:
                return;
                break;
            case 1:
                for (int i = 0; i < N; i++) {
                    journal[i].Print();
                }
                break;
            case 2:
                cout << "inputs number journal";
                int one, two;
                cin >> one >> two;
                journal[one].sum_journal(journal[two]);
                break;
            case 3:
                int one_1;
                cin >> one_1;
                journal[one_1].edit_journal("Journal_Biysk_rbochi", 228, 1337);
                break;

            default:
                break;
        }
    }
}
