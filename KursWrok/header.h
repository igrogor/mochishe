#ifndef HEADERS
#define HEADERS

#include <iostream>
#include <cstring>

class Car
{
private:
    int speed;
    char* name;
    int mas;
    char classCar;
public:
    Car();
    Car(int speed_n, char* name_n, int mas_n, char classCar_n);
    ~Car();

};




#endif
