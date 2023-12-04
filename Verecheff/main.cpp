#include "Header.h"
#include <locale.h>
#include <windows.h>

char* enter() { //������� ��� ����� � �������
	char* data = NULL;
	char c;
	int size = 0;
	while ((c = getchar()) != '\n' && c != EOF && c != ' ') {

		if (!isdigit(c) && c != '-') { //�������� ����, ��� �������� ����� 
			printf("������ �����. ������� �����, ���������� ����� �� 0 �� 9 � ���� -\n");
			delete[] data;  
			exit(NULL);  //��������� ��������� � ������ ������
		}

		char* tempData = new char[size + 1];

		for (int i = 0; i < size; ++i) {
			tempData[i] = data[i];
		}

		tempData[size++] = c;
		delete[] data;

		data = tempData;
	}

	char* tempData = new char[size + 1];

	for (int i = 0; i < size; ++i) {
		tempData[i] = data[i];
	}

	tempData[size++] = '\0';

	delete[] data;

	return tempData;
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	IntegerM* t = new IntegerM();
	cout << "�������� num � �������, ��������� ������������� �� ���������: " << t->getNum() << endl;
	delete t;

	cout << "������� ������ �����: ";
	char* num = NULL;
	num = enter();
	IntegerM test(num); //���� ������������ � �����������
	delete[] num;
	test.changeNum(); //���� ������� ����� ����� 

	cout << "������� ������ �����: ";
	num = enter();
	IntegerM test2(num);
	delete[] num;

	IntegerM test3(test2);

	IntegerM result = test + test3; ////���� ���������� ��������� �������� �������� ������
	cout << "����� ��������� ��������: " << result.getNum() << endl; //���� ������� ��������� ������ �� ������� ������

	IntegerM test4 = test;
	cout << "�������� �������, �������� ��������� ������ ������: " << test4.getNum() << endl; //���� ���������� ��������� ������������

	result = test + test4++;
	cout << "�������� ����� �������� � ������������� ����������: " << result.getNum() << " �������� ������� ����� ����������: " << test4.getNum() << endl;

	int a = (int)test4;
	cout << "�������� ������������ � int �������: " << a << endl; //���� ���������� ��������� ���������� � ���� int

	result = test - test3;
	cout << "������� ��������� ��������: " << result.getNum() << endl; //���� ���������� ������������� ������� ��������� 

	//ofstream fileText("textFile.txt"); //���� ����� ������� � ����� 
	//fileText << test;
	//fileText.close();

	//ifstream file("binFile.bin", ifstream::binary); //���� ������ ������� �� ��������� ����� 
	//file >> result;
	//cout << "�������� �������, ��������� �� �����: " << result.getNum() << endl;
	//file.close();

	cout << "\n������� �����: ";
	num = enter();
	
	IntegerMod abaraba(num);
	//IntegerMod abaraba2 = abaraba;
	//cout << "�������� �������������� �������: " << abaraba.getNum() << endl;

	//IntegerM *p, *r;
	//r = &abaraba;
	//p = &result;

	//cout << r->getNum() << " " << p->getNum() << endl;

	Deque testiks(4, &test, &test3, &result, &abaraba);
	testiks.outputElements(&Deque::readLeft);

	testiks.outputElementByID(4);

	testiks.outputElementByMean(&result);

	testiks.pasteElement(3, &test2);
	testiks.outputElements(&Deque::readLeft);

	testiks.del(3);
	testiks.outputElements(&Deque::readLeft);


	return 0;
}