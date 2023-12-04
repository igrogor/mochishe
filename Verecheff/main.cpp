#include "Header.h"
#include <locale.h>
#include <windows.h>

char* enter() { //функция для ввода с консоли
	char* data = NULL;
	char c;
	int size = 0;
	while ((c = getchar()) != '\n' && c != EOF && c != ' ') {

		if (!isdigit(c) && c != '-') { //проверка того, что вводится цифра 
			printf("Ошибка ввода. Введите число, содержащее цифры от 0 до 9 и знак -\n");
			delete[] data;  
			exit(NULL);  //завершить программу в случае ошибки
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
	cout << "Значение num в объекте, созданным конструктором по умолчанию: " << t->getNum() << endl;
	delete t;

	cout << "Введите первое число: ";
	char* num = NULL;
	num = enter();
	IntegerM test(num); //тест конструктора с параметрами
	delete[] num;
	test.changeNum(); //тест функции смены числа 

	cout << "Введите второе число: ";
	num = enter();
	IntegerM test2(num);
	delete[] num;

	IntegerM test3(test2);

	IntegerM result = test + test3; ////тест перегрузки оператора сложения объектов класса
	cout << "Сумма введенных значений: " << result.getNum() << endl; //тест функции получения строки из объекта класса

	IntegerM test4 = test;
	cout << "Значение объекта, которому присвоили другой объект: " << test4.getNum() << endl; //тест перегрузки оператора присваивания

	result = test + test4++;
	cout << "Значение суммы объектов с использование инкремента: " << result.getNum() << " Значение объекта после инкремента: " << test4.getNum() << endl;

	int a = (int)test4;
	cout << "Значение приведенного к int объекта: " << a << endl; //тест перегрузки оператора приведения к типу int

	result = test - test3;
	cout << "Разница введенных значений: " << result.getNum() << endl; //тест перегрузка дружественной функции вычитания 

	//ofstream fileText("textFile.txt"); //тест ввода объекта в файлы 
	//fileText << test;
	//fileText.close();

	//ifstream file("binFile.bin", ifstream::binary); //тест вывода объекта из бинарного файла 
	//file >> result;
	//cout << "Значение объекта, введеного из файла: " << result.getNum() << endl;
	//file.close();

	cout << "\nВведите число: ";
	num = enter();
	
	IntegerMod abaraba(num);
	//IntegerMod abaraba2 = abaraba;
	//cout << "Значение скопированного объекта: " << abaraba.getNum() << endl;

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