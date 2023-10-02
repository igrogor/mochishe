#ifndef HEADERS
#define HEADERS

#include <time.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#define N 20

class Journal {
    int number;

   public:
    void set_name(const char *name);
    void set_year(int year);
    void set_circulation(int circulation);
    void Print();

   private:
    char name[N];
    int year;
    int circulation;
};

#endif