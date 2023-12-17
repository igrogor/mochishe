#ifndef HEADERS
#define HEADERS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <bitset>
#include <cstdarg>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#pragma once
#define N 5

using namespace std;

class Journal {
   protected:
    char* name;
    int count_a_year;
    int circulation;

   public:
    friend class FriendJournal;
    Journal();
    Journal(const char* newname, int newcount, int newcirc);
    Journal(const Journal& p);
    ~Journal();
    void set_name(const char* nam);
    void set_year(int year);
    void set_circulation(int circulation);
    int get_circulation();
    int get_year();
    char* get_name();
    virtual void print();
    void sum_journal(Journal& other);
    void edit_journal(const char* new_name, int new_year, int new_circulation);
    virtual Journal operator+(Journal& other);
    virtual const Journal& operator=(const Journal& other);
    friend Journal operator-(const Journal& one, const Journal& other);
    Journal& operator++();
    Journal operator++(int);
    // operator char();
    operator bool();

    void readFromFile(const char* filename);
    void writeToFile(const char* filename);
    void writeToBinaryFile(const char* filename);
    void readFromBinaryFile(const char* filename);

    // friend ostream& operator<<(ostream& os, const Journal& journal);
    // friend istream& operator>>(istream& is, Journal& journal);

    // friend ofstream& operator<<(ofstream& ofs, const Journal& journal);
    // friend ifstream& operator>>(ifstream& ifs, Journal& journal);

    friend std::ostream& operator<<(std::ostream& os, const Journal& journal);
    friend std::istream& operator>>(std::istream& is, Journal& journal);
};

Journal operator-(const Journal& one, const Journal& other);
char* severity_char(char* fchar, char* schar);
int countDigits(int number);

class Comics : public Journal {
   private:
    bool shornsh;

   public:
    Comics();
    Comics(bool yorn, const char* newname, int newcount, int newcirc);
    Comics(const Comics& p);
    void sort(Comics Comics[]);
    void print();
    bool get_shornsh();
};

class Gazette : public Journal {
   private:
    int number_of_articles;

   public:
    Gazette();
    Gazette(int number_of_articles, char* newname, int newcount, int newcirc);
    Gazette(const Gazette& p);
    Gazette operator+(Gazette& other);
    void print_gazette();
    Gazette operator=(Gazette& other);
};

//--------------------------------------------------------------------------------------//

class deque {
   protected:
    struct Node {
        Node* next;
        Node* prev;
        int num_in_list;
        Comics object;
    };
    Node* head;
    Node* tail;
    Node* current;
    int size_list;
    int id_node;

   public:
    deque();
    deque(int id, ...);
    deque(const deque&);
    Node* initializetr_list(Comics obj);
    void add(Comics obj);
    void input_Node(int num_in_list, Comics object);
    Comics* readLeft();
    void del(int id_node);
    void deleteLeftNode();
    void deleteRightNode();
    Comics* outputElementByID(int id_node);
    void printElements();
    Node* search(int num_in_list);
    ~deque();
};

#endif
