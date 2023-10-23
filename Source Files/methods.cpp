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

Journal operator-(const Journal& one, const Journal& other) {
    int dif_circ = one.circulation - other.circulation;
    int dif_count = one.count_a_year - other.count_a_year;
    // char* new_name = new char[strlen(severity_char(one.name, other.name)) + 1];
    // new_name = severity_char(one.name, other.name);
    char * new_name = "opa+dcf";
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

char* severity_char(char* str1, char* str2) {
    char* max_str;

    if (strlen(str1) > strlen(str2)) {
        char* max_str = str1;
    } else {
        char* max_str = str2;
    }

    char* res_str = new char[strlen(max_str)];

    cout << res_str;

    for (int i = 0, j = 0; i < strlen(max_str); i++) {
        if (*(str1 + i) == '\0') {
            *(res_str + i) = *(str2 + i);
        }
        if (*(str2 + i) == '\0') {
            *(res_str + i) = *(str1 + i);
        } else {
            *(res_str + i) = *(str1 + i) - *(str2 + i);
        }
        cout << res_str;
    }

    cout << res_str;

    return res_str;
}

char* Journal::operator char(Journal& other) {
    
    char * main_str = new char[strlen(other.name) + countDigits(other.circulation) + countDigits(other.count_a_year) + 1];
    char * main_str_int = new char[countDigits(other.circulation) + countDigits(other.count_a_year) + 1];
    strncpy(main_str_int, (char*)other.circulation, countDigits(other.circulation) + 1);
    strncat(main_str_int, (char*)other.count_a_year, (strlen(main_str_int) + strlen((char*)other.count_a_year) + 1));

    
    strncpy(main_str,other.name, strlen(other.name));
    strncat(main_str, main_str_int, (strlen(main_str_int) + strlen(other.name) + 1));

    return *main_str;
}

int countDigits(int number) {
    std::string numberString = std::to_string(number);
    return numberString.length();
}