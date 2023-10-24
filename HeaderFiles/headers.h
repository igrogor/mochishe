#ifndef HEADERS
#define HEADERS

#include <string.h>
#include <time.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Journal {
   private:
    char* name;
    int count_a_year;
    int circulation;

   public:
    friend class FriendJournal;
    Journal();
    Journal(char* newname, int newcount, int newcirc);
    Journal(const Journal& p);
    ~Journal();
    void set_name(const char* nam);
    void set_year(int year);
    void set_circulation(int circulation);
    void print();
    void sum_journal(Journal& other);
    void edit_journal(const char* new_name, int new_year, int new_circulation);
    void operator+(Journal& other);
    const Journal& operator=(const Journal& other);
    friend Journal operator-(const Journal& one, const Journal& other);
    Journal& operator++();
    Journal operator++(int);
    // operator char();
    operator bool();
};

Journal operator-(const Journal& one, const Journal& other);
char* severity_char(char* fchar, char* schar);
int countDigits(int number);

#endif
