#include "../HeaderFiles/headers.h"

using namespace std;

void Journal::Print() { cout << name << "\t " << year << "\t " << circulation << endl; }

void Journal::set_name(const char *name) { strcpy(this->name, name); }

void Journal::set_year(int year) { this->year = year; }

void Journal::set_circulation(int circulation) { this->circulation = circulation; }

void Journal::sum_journal(Journal &other) {
    strncat(this->name, other.name, N - strlen(this->name));
    this->year += other.year;
    this->circulation += other.circulation;
}

void Journal::edit_journal(const char *new_name, int new_year, int new_circulation) {
    set_name(new_name);
    set_year(new_year);
    set_circulation(new_circulation);
}
