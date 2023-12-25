#include "./header.h"

Car::Car() {
    char* name = nullptr;
    int speed = 0;
    int mas = 0;
    char classCar = '-';
}

Car::Car(int speed_n, char* name_n, int mas_n, char classCar_n) {
    char* name = new char[strlen(name_n) + 1];
    strncpy(name, name_n, strlen(name_n) + 1);//throw

    int speed = speed_n;
    int mas = mas_n;
    char classCar = classCar_n;
}

Car::~Car() {
    delete[] name;
}


