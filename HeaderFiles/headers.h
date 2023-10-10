#ifndef HEADERS
#define HEADERS

#include <time.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
#define N 4

class Journal {
    int number;

   public:
    void set_name(char *nam);
    void set_year(int year);
    void set_circulation(int circulation);
    void Print();
    void sum_journal(Journal &other);
    void edit_journal(char *new_name, int new_year, int new_circulation);

   private:
    char *name;
    int year;
    int circulation;
};

#endif