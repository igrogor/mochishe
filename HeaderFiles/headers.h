#ifndef HEADERS
#define HEADERS



#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;


class Journal {
   int number;

   public:
    char* name;
    int year;
    int circulation;
    void Print(); 
    void add_journal();

};

    #endif