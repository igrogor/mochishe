#include <cstdio>
#include <initializer_list>
#include <iterator>

#include "../HeaderFiles/headers.h"

using namespace std;

Journal::Journal() {
    name = nullptr;
    count_a_year = 0;
    circulation = 0;
}

// 4294967296

Journal::Journal(const char* newname, int newcount, int newcirc) {
    if (sizeof(newname) > 4294967296) throw "lack of memory\n";
    name = new char[strlen(newname) + 1];
    strncpy(name, newname, strlen(newname) + 1);

    if (newcount < 1500 || newcount > 2023) throw "exceeding the range of permissible values\n";
    count_a_year = newcount;

    if (newcirc < 0 || newcirc > 1000000000) throw "exceeding the range of permissible values\n";
    circulation = newcirc; /* code */
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

char* Journal::get_name() { return name; }

bool Comics::get_shornsh() { return shornsh; }

void Journal::set_year(int newyear) { count_a_year = newyear; }

int Journal::get_year() { return count_a_year; }

void Journal::set_circulation(int newcirc) { circulation = newcirc; }

int Journal::get_circulation() { return circulation; }

void Journal::sum_journal(Journal& other) {
    char* oldname = name;
    name = new char[strlen(oldname) + strlen(other.name) + 1];
    strncpy(name, oldname, strlen(oldname) + 1);
    strncat(name, other.name, (strlen(oldname) + strlen(other.name) + 1));
    this->count_a_year += other.count_a_year;
    this->circulation += other.circulation;
    delete[] oldname;
}

Journal Journal::operator+(Journal& other) {
    char* oldname = name;
    char* kapusta;
    int kabachok;
    int perec;
    name = new char[strlen(oldname) + strlen(other.name) + 1];
    kapusta = new char[strlen(oldname) + strlen(other.name) + 1];
    strncpy(name, oldname, strlen(oldname) + 1);
    strncat(name, other.name, (strlen(oldname) + strlen(other.name) + 1));

    kabachok = count_a_year;
    perec = circulation;

    kabachok += other.count_a_year;
    perec += other.circulation;

    strcpy(kapusta, name);

    strcpy(name, oldname);

    delete[] oldname;
    return Journal(kapusta, kabachok, perec);
}

void Journal::edit_journal(const char* new_name, int new_year, int new_circulation) {
    set_name(new_name);
    set_year(new_year);
    set_circulation(new_circulation);
}

Journal operator-(const Journal& one, const Journal& other) {
    int dif_circ = one.circulation - other.circulation;
    int dif_count = one.count_a_year - other.count_a_year;
    char* new_name;
    new_name = severity_char(one.name, other.name);
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

// char* severity_char(char* str1, char* str2) {
//     char* max_str;

//     if (strlen(str1) > strlen(str2)) {
//         char* max_str = str1;
//     } else {
//         char* max_str = str2;
//     }

//     char* res_str = new char[strlen(max_str) + 1];

//     cout << res_str;

//     for (int i = 0; i < strlen(max_str); i++) {
//         if (*(str1 + i) == '\0') {
//             *(res_str + i) = *(str2 + i);
//         }
//         if (*(str2 + i) == '\0') {
//             *(res_str + i) = *(str1 + i);
//         } else {
//             *(res_str + i) = *(str1 + i) - *(str2 + i);
//         }
//         cout << res_str;
//     }

//     cout << res_str;

//     return res_str;
// }

char* severity_char(char* fchar, char* schar) {
    char* min_char = strlen(fchar) < strlen(schar) ? fchar : schar;
    char* max_char = strlen(fchar) >= strlen(schar) ? fchar : schar;
    char* res_char = new char[strlen(max_char) + 1];

    for (int i = 0; i < strlen(min_char); i++) {
        res_char[i] = fchar[i] - schar[i] ? fchar[i] - schar[i] : '0';
    }
    for (int i = strlen(min_char); i < strlen(max_char); i++) {
        res_char[i] = max_char[i];
    }

    res_char[strlen(max_char)] = 0;
    return res_char;
}

// Journal::operator char() {

//     char * main_str = new char[strlen(name) + countDigits(circulation) + countDigits(count_a_year) + 1];
//     char * main_str_int = new char[countDigits(circulation) + countDigits(count_a_year) + 1];

//     strncpy(main_str_int, (char*)circulation, countDigits(circulation) + 1);
//     strncat(main_str_int, (char*)count_a_year, (strlen(main_str_int) + strlen((char*)count_a_year) + 1));

//     strncpy(main_str,name, strlen(name));
//     strncat(main_str, main_str_int, (strlen(main_str_int) + strlen(name) + 1));

//     return *main_str;
// }

// int countDigits(int number) {
//     std::string numberString = std::to_string(number);
//     return numberString.length();
// }

Journal::operator bool() {
    if (name == nullptr && count_a_year == 0 && circulation == 0) {
        return 0;
    } else {
        return 1;
    }
}

// void Journal::operator <(Journal& one) {
//     cout << name  << count_a_year << circulation << endl;
// }

// ostream& operator<<(ostream& os, const Journal& journal) {
//     os << journal.name << " " << journal.count_a_year << " " << journal.circulation;
//     return os;
// }

// istream& operator>>(istream& is, Journal& journal) {
//     is >> journal.name >> journal.count_a_year >> journal.circulation;
//     return is;
// }

// ofstream& operator<<(ofstream& ofs, const Journal& journal) {
//     ofs.write((char*)&journal, sizeof(Journal));
//     return ofs;
// }

// ifstream& operator>>(ifstream& ifs, Journal& journal) {
//     ifs.read((char*)&journal, sizeof(Journal));
//     return ifs;
// }

// fghdhrfghfghjnfghj

std::ostream& operator<<(std::ostream& os, const Journal& journal) {
    os << "Name: " << journal.name << std::endl;
    os << "Count a year: " << journal.count_a_year << std::endl;
    os << "Circulation: " << journal.circulation << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Journal& journal) {
    char temp_name[100];  // Предполагается, что имя журнала не превышает 100 символов
    int temp_count, temp_circulation;
    is >> temp_name >> temp_count >> temp_circulation;
    journal.edit_journal(temp_name, temp_count, temp_circulation);
    return is;
}

// Ввод и вывод в текстовый файл
void Journal::writeToFile(const char* filename) {
    std::ofstream file(filename);
    file << *this;
    file.close();
}

void Journal::readFromFile(const char* filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> *this;
        file.close();
    }
}

// Ввод и вывод в двоичный файл
void Journal::writeToBinaryFile(const char* filename) {
    std::ofstream file(filename, ios::binary);
    if (file.is_open()) {
        int len = strlen(name) + 1;
        file.write((char*)&len, sizeof(int));

        // for (int i = 0; i < len ;i++) {
        //     file.write((char*)&name[i], sizeof(char));
        // }

        file.write(name, len);
        file.write((char*)&count_a_year, sizeof(int));
        file.write((char*)&circulation, sizeof(int));

        file.close();
    }
}

void Journal::readFromBinaryFile(const char* filename) {
    std::ifstream file(filename, ios::binary);
    if (file.is_open()) {
        int len = 0;
        file.read((char*)&len, sizeof(int));
        delete[] name;
        name = new char[len];
        for (int i = 0; i < len; i++) {
            file.read((char*)&name[i], sizeof(char));
        }
        file.read((char*)&count_a_year, sizeof(int));
        file.read((char*)&circulation, sizeof(int));

        file.close();
    }
}

//
// Конструкторы:
// daemon(int br « 10){brain = br;};
// daemon(color sk) : monstr (sk) {brain = 10;}
// daemon(char * nam) : monstr (nam) {brain = 10:}
// daemon(daemon &M) : monstr (M) {brain = M.brain;}

Comics::Comics() { shornsh = 0; }

Comics::Comics(bool param, const char* newname, int newcount, int newcirc)
    : Journal(newname, newcount, newcirc) {
    shornsh = param;
}

Comics::Comics(const Comics& p) : Journal(p) { shornsh = p.shornsh; }

void Comics::sort(Comics comics[]) {
    for (int i = 0; i < N; i++) {
        if (comics->shornsh == 1) {
            comics->print();
        }
    }
    for (int i = 0; i < N; i++) {
        if (comics->shornsh == 0) {
            comics->print();
        }
    }
}

void Comics::print() {
    Journal::print();
    cout << shornsh << "\n";
}

Gazette::Gazette() { number_of_articles = 0; }

Gazette::Gazette(int param, char* newname, int newcount, int newcirc) : Journal(newname, newcount, newcirc) {
    if (param < 0) {
        throw "tahe number of articles cannot be negative\n";
    }

    number_of_articles = param;
}

Gazette::Gazette(const Gazette& p) : Journal(p) { number_of_articles = p.number_of_articles; }

Gazette Gazette::operator+(Gazette& other) {
    Journal temp = this->Journal::operator+(other);
    int new_number_of_articles = this->number_of_articles + other.number_of_articles;
    return Gazette(new_number_of_articles, temp.get_name(), temp.get_year(), temp.get_circulation());
}

void Gazette::print_gazette() {
    if (name == nullptr)
        cout << "u/n name\t";
    else
        cout << name << "\t ";
    if (count_a_year == 0)
        cout << "u/n count a year\t";
    else
        cout << count_a_year << "\t ";
    if (circulation == 0)
        cout << "u/n circulation\t";
    else
        cout << circulation << "\t";
    if (number_of_articles == 0)
        cout << "u/n number_of_articles\n";
    else
        cout << number_of_articles << "\n";
}
Gazette Gazette::operator=(Gazette& other) {
    Journal temp = this->Journal::operator=(other);
    number_of_articles = other.number_of_articles;
    return Gazette(number_of_articles, temp.get_name(), temp.get_year(), temp.get_circulation());
}

// ===================================================================================//

deque::deque() {
    head = NULL;
    tail = NULL;
    current = NULL;
    size_list = 0;
    id_node = 0;
}

deque::deque(int size, ...) {
    size_list = size;
    head = new Node;
    tail = new Node;
    current = head;
    id_node = 0;

    va_list args;
    va_start(args, size);
    Comics object = va_arg(args, Comics);
    tail = initializetr_list(object);

    for (int i = 0; i < size; i++) {
        object = va_arg(args, Comics);
        add(object);
    }
    tail->next = NULL;
}

deque::deque(const deque& origin_object) {
    tail = new Node;
    head = new Node;
    current = head;
    size_list = origin_object.size_list;
    id_node = 0;

    Node* point = head;
    Comics object = point->object;
    tail = initializetr_list(object);
    point = point->next;

    for (int i = 1; i < origin_object.size_list; i++) {
        object = point->object;
        add(object);
        point = point->next;
    }
    tail->next = NULL;
}

deque::Node* deque::initializetr_list(Comics object) {
    id_node = 1;
    head->object = object;
    head->prev = NULL;
    head->num_in_list = id_node++;

    return head;
}

void deque::add(Comics object) {
    Node* new_Node = new Node;
    tail->next = new_Node;
    new_Node->object = object;
    new_Node->prev = tail;
    new_Node->num_in_list = id_node++;
    tail = new_Node;
}

void deque::input_Node(int num_in_list, Comics object) {
    current = search(num_in_list);
    if (current != NULL) {
        Node* new_Node = new Node;
        Node* newNode = new Node;
        newNode->object = object;
        newNode->prev = current->prev;
        newNode->num_in_list = current->num_in_list;
        newNode->next = current;
        current->prev->next = newNode;
        current->prev = newNode;
        size_list++;
        for (int i = num_in_list; i < size_list; i++) {
            current->num_in_list++;
            current = current->next;
        }
    } else {
        cout << endl << "ERROR, node not such\n" << endl;
    }
}

Comics* deque::readLeft() {
    Comics* object = &current->object;
    current = current->next;
    return object;
}

deque::Node* deque::search(int num_in_list) {
    current = head;
    if (num_in_list == 0 || num_in_list > size_list) {
        cout << "Error, no such object\n" << endl;
        return NULL;
    }
    for (int i = 0; current != NULL && num_in_list != current->num_in_list; i++) {
        current = current->next;
    }
    if (num_in_list == current->num_in_list) return current;
    return nullptr;
}

void deque::printElements() {
    current = head;
    for (int i = 0; i < size_list; i++) {
        Journal* obj = (Journal*)readLeft();
        obj->print();
    }
}

Comics* deque::outputElementByID(int id_node2) {
    if (search(id_node2) != nullptr) {
        Journal* p = (Journal*)&(current->object);
        p->print();
        return &(current->object);
    }
    return nullptr;
}

void deque::deleteLeftNode() {
    if (head != tail) {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    } else {
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    size_list--;
}

void deque::deleteRightNode() {
    if (head != tail) {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    } else {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    size_list--;
}

void deque::del(int num_in_list) {
    current = search(num_in_list);
    if (current != nullptr) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        Node* buf = new Node;
        buf = current->next;
        delete current;
        current = buf;
        size_list--;
        for (int i = num_in_list; i <= size_list; i++) {
            current->num_in_list--;
            current = current->next;
        }
    } else
        cout << "\nError" << endl;
}

deque::~deque() {
    for (int i = 0; i < size_list; i++) {
        deleteLeftNode();
    }

    delete head, tail, current;
}
