#include "../HeaderFiles/headers.h"

using namespace std;

void Journal::Print() { cout << name << "\t " << year << "\t " << circulation << endl; }

void Journal::set_name(const char *name) { strcpy(this->name, name); }

void Journal::set_year(int year) { this->year = year; }
void Journal::set_circulation(int circulation) { this->circulation = circulation; }