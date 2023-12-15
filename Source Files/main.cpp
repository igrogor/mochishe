
// Добавить в классы и демонстрационную программу
// обработку исключений при возникновении ошибок:
// недостатка памяти,
// выхода за пределы диапазона
// допустимых значений и т.д.
// Дополнить демонстрационную программу так,
// чтобы она демонстрировала обработку исключений.

#include "../HeaderFiles/headers.h"

void main_window();

int main() {
    main_window();

    return 0;
}

void main_window() {
    // Journal journal1[N];

    // for (int i = 0; i < N; i++)
    // 	journal1[i].print();
    // cout << endl;

    // journal1[0].edit_journal("testname1", 1, 567889);
    // journal1[1].edit_journal("testname2", 2, 165743);
    // journal1[2].edit_journal("testname3", 5, 465732);
    // journal1[3].edit_journal("testname4", 3, 149507);
    // journal1[4].edit_journal("testname5", 2, 157202);

    // for (int i = 0; i < N; i++) journal1[i].print();
    // cout << endl;

    // Journal *ja = new Journal((char *)"jajaj", 5, 4);
    // Journal jb = Journal((char *)"shishka", 10, 15);

    // Journal sum1 = Journal((char *)"Oleg", 2, 135);
    // Journal sum2 = Journal((char *)"Mongol", 11, 155);
    // Journal sum;

    // sum1.print();

    // sum = sum1 + sum2;

    // sum.print();
    // sum1.print();

    // Journal jc;

    // jc = sum1 - sum2;

    // jb.print();

    // jc.print();

    // (++jc).print();

    // (jc++).print();
    // jc.operator++(1);
    // jc.print();

    // cout << bool(jc);

    // Journal journal2("Constructor with param", 4, 354362);
    // journal2.print();
    // cout << endl;
    // Journal copy = journal1[3];
    // copy.print();
    // cout << endl;
    // journal1[0].sum_journal(journal1[2]);
    // journal1[0].print();
    // journal1[0] + journal1[2];
    // journal1[0].print();
    // //Вывод объекта в текстовый файл

    // cout << "-----------------------------------------------------------"<<endl;

    // ofstream textFile("journal.txt");
    // textFile << jc;
    // textFile.close();

    // // Вывод объекта в двоичный файл
    // ofstream binaryFile("journal.bin", ios::binary);
    // binaryFile << jc;
    // binaryFile.close();

    // // Ввод объекта из текстового файла
    // ifstream textInputFile("journal.txt");
    // Journal journalFromTextFile;
    // textInputFile >> journalFromTextFile;
    // cout << "jc from text file: " << journalFromTextFile << endl;
    // textInputFile.close();

    // // Ввод объекта из двоичного файла
    // ifstream binaryInputFile("journal.bin", ios::binary);
    // Journal journalFromBinaryFile;
    // binaryInputFile >> journalFromBinaryFile;
    // cout << "jc from binary file: " << journalFromBinaryFile << endl;
    // binaryInputFile.close();

    // Journal journal;
    // std::cin >> journal;   // Ввод данных с клавиатуры
    // std::cout << journal;  // Вывод данных на экран

    // // ournal.writeToFile("journal.txt");   // Запись в текстовый файл
    // // journal.readFromFile("journal.txt");  // Чтение из текстового файла
    // ofstream file("journal.txt");
    // file << journal;
    // file.close();
    // journal.writeToBinaryFile("journal.dat");   // Запись в двоичный файл
    // journal.readFromBinaryFile("journal.dat");  // Чтение из двоичного файла
    // journal.print();

    // comics Marvel[N];
    // for (int i = 0; i < N; i++) {
    //     Marvel[i].print();
    // }

    // cout << endl;

    // for (int i = 0; i < N; i++) {
    // }

    // Marvel->sort(Marvel);

    // Journal* ptr = new Journal();
    // ptr->print();
    // delete ptr;

    // ptr = new Comics();
    // ptr->print();
    // delete ptr;

    // Gazette Gazette1(123, "fbv",123 ,213);
    // Gazette Gazette2(123, "2bf",123 ,213);
    // Gazette gaz = Gazette1 + Gazette2;
    // jc.print();
    // gaz.print_gazette();
    // Comics C1(1, "swfewrver", 12, 2563);
    // Comics C2(0, "srvefvr", 132, 21233);
    // Comics C3(1, "srvdfver", 1562, 23453);
    // Comics C4(0, "wefsrvwefer", 112, 23453);


    // deque obj1(4,C1,C2,C3,C4);

    // obj1.printElements();
    // obj1.deleteRightNode();
    // obj1.printElements();
    // obj1.deleteLeftNode();
    // obj1.printElements();

    //obj1.outputElementByID(3);


    Journal one("sdfvdsf", 213, 0);
    Comics two(2,"dfsdf",32345,334);
    Gazette three(-34,"fdg",435,436);


    one.print();
    two.print();
    three.print();
    
    std::cout << '\n' << "The end" << '\n';
    
}
