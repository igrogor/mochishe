#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <bitset>
#include <cstdarg>

using namespace std;

class Integer {
	virtual int changeNum();
	virtual char* getNum();
};

class IntegerM : public Integer{
public:
	IntegerM(); //����������� �� ���������
	IntegerM(char*); //�����������, ���������� �����
	IntegerM(const IntegerM&); //����������� �����������
	~IntegerM(); //����������

	IntegerM operator+(const IntegerM&)const; //���������� ��������� ��������
	IntegerM& operator=(const IntegerM&); //���������� ��������� ������������
	IntegerM& operator++(); //���������� ��������� ����������� ����������
	IntegerM operator++(int); //���������� ��������� ������������ ����������
	friend IntegerM operator-(const IntegerM&, const IntegerM&); //���������� ��������� ���������, ��������������, ��� ������������� �������

	operator int(); //���������� ��������� ���������� � ���� int

	friend istream& operator>>(istream&, IntegerM&); //���������� ��������� �����/�������� ������� �� �����
	friend ostream& operator<<(ostream&, IntegerM&); //���������� ��������� ������/������ ������� � ����

	int changeNum(); //������� ����� �����
	int countLenght(char*); //������� �������� ����� �������
	char* getNum();  //������� �������� �����
	int getLenght();  //������� �������� ����� �����

protected:
	int arrayLenght;
	char* num;
};

class IntegerMod : public IntegerM {
public:
	IntegerMod(); //����������� �� ���������
	IntegerMod(char*); //�����������, ���������� �����
	IntegerMod(const IntegerMod&); //����������� �����������

	IntegerMod& operator= (const IntegerMod&);

	bool getNegNum();
	char* getNum();
	int changeNum();

protected:
	bool negNum;
};

class Deque{
protected:
	struct Node {
		IntegerM* obj;
		Node* next; 
		Node* prev;
		int id;
	};

	Node* point_begin;
	Node* point_end;
	Node* point_current;
	int countElements;
	int currentID;

public:
	Deque(); //����������� �� ���������
	Deque(int count, ...); //�����������, ���������� �������
	Deque(const Deque&); //����������� �����������

	Node* first(IntegerM* obj);
	void add(IntegerM* obj);
	void pasteElement(int id, IntegerM*);
	IntegerM* readLeft();
	IntegerM* readRight();
	IntegerM* sampleLeft();
	IntegerM* sampleRight();
	void del(int id);
	void deleteLeftNode();
	void deleteRightNode();
	Node* getPointBegin();
	Node* getPointEnd();
	int getCountElements();
	void setPoint(Node*);
	void outputElements(IntegerM* (Deque::*)());
	IntegerM* outputElementByID(int id);
	int outputElementByMean(IntegerM*);
	Node* search(int);
	Node* search(IntegerM*);

	~Deque(); //����������
};