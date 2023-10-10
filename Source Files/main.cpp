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

    for (int i = 0; i < N - 1; i++) {
        journal[i].set_year(1835 + i);
        journal[i].set_name("PlayBoy");
        journal[i].set_circulation(12000 + i);
    }
    journal[3].set_year(1835234534);
    journal[3].set_name("ABOBUSdfghgrgfvdfgdfdfwfxsfsdfsdfsdf   3");
    journal[3].set_circulation(12000234234);

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
                cout << "input num journal.." << endl;
                cin >> one_1;
                cout << "input new: name - year - circulation " << endl;
                char *new_name;
                int new_year, new_circulation;
                cin >> new_name;
                cin >> new_year;
                cin >> new_circulation;
                journal[one_1].edit_journal(new_name, new_year, new_circulation);
                break;

            default:
                break;
        }
    }
}
