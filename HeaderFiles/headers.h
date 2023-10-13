#ifndef HEADERS
#define HEADERS

#include <time.h>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

class Journal {
private:
	char* name;
	int count_a_year;
	int circulation;
public:
	Journal();
	Journal(const char* newname, int newcount, int newcirc);
	Journal(const Journal& p);
	~Journal();
	void set_name(const char* nam);
	void set_year(int year);
	void set_circulation(int circulation);
	void print();
	void sum_journal(Journal& other);
	void edit_journal(const char* new_name, int new_year, int new_circulation);
};

#endif
