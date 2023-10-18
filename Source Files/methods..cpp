#include "../HeaderFiles/headers.h"

using namespace std;

Journal::Journal() {
    name = nullptr;
    count_a_year = 0;
    circulation = 0;
}

Journal::Journal(char* newname, int newcount, int newcirc) {
    name = new char[strlen(newname) + 1];
    strncpy(name, newname, strlen(newname) + 1);
    count_a_year = newcount;
    circulation = newcirc;
}

Journal::Journal(const Journal& p) {
    if (p.name != nullptr) {
        name = new char[strlen(p.name) + 1];
        strncpy(name, p.name, strlen(p.name) + 1);
    }
    count_a_year = p.count_a_year;
    circulation = p.circulation;
}

Journal::~Journal() { delete[] name; }

void Journal::print() {
    if (name == nullptr)
        cout << "u/n name\t";
    else
        cout << name << "\t ";
    if (count_a_year == 0)
        cout << "u/n count a year\t";
    else
        cout << count_a_year << "\t ";
    if (circulation == 0)
        cout << "u/n circulation\n";
    else
        cout << circulation << "\n";
}

void Journal::set_name(const char* nam) {
    name = new char[strlen(nam) + 1];
    strncpy(name, nam, strlen(nam) + 1);
}
void Journal::set_year(int newyear) { count_a_year = newyear; }

void Journal::set_circulation(int newcirc) { circulation = newcirc; }

void Journal::sum_journal(Journal& other) {
    char* oldname = name;
    name = new char[strlen(oldname) + strlen(other.name) + 1];
    strncpy(name, oldname, strlen(oldname) + 1);
    strncat(name, other.name, (strlen(oldname) + strlen(other.name) + 1));
    this->count_a_year += other.count_a_year;
    this->circulation += other.circulation;
    delete[] oldname;
}

void Journal::operator+(Journal& other) {
    char* oldname = name;
    name = new char[strlen(oldname) + strlen(other.name) + 1];
    strncpy(name, oldname, strlen(oldname) + 1);
    strncat(name, other.name, (strlen(oldname) + strlen(other.name) + 1));
    this->count_a_year += other.count_a_year;
    this->circulation += other.circulation;
    delete[] oldname;
}

void Journal::edit_journal(const char* new_name, int new_year, int new_circulation) {
    set_name(new_name);
    set_year(new_year);
    set_circulation(new_circulation);
}

Journal operator-(const Journal& one,const Journal& other) {
	int dif_circ = one.circulation - other.circulation;
	int dif_count = one.count_a_year - other.count_a_year;
	char* new_name = new char[strlen("pohui") + 1];
	strcpy(new_name, "pohui");
	return Journal(new_name, dif_count, dif_circ);
}

const Journal& Journal::operator=(const Journal& other) {
    if (&other == this) {
        return *this;
    }
    if (other.name) {
		if (name) delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	circulation = other.circulation;
    count_a_year = other.count_a_year;
    return *this;
}

Journal& Journal::operator++() {
	++circulation;
	return *this;
}
Journal Journal::operator++(int) {
	Journal temp = *this;
	++*this;
	return temp;
}