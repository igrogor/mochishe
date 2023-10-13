

#include "../HeaderFiles/headers.h"
#define N 5

void main_window();

int main() {
	main_window();

	return 0;
}

void main_window() {
	Journal journal1[N]; //��������� ����������� �� ���������
	for (int i = 0; i < N; i++)
		journal1[i].print();
	cout << endl;
	journal1[0].edit_journal("testname1", 1, 567889);
	journal1[1].edit_journal("testname2", 2, 165743);
	journal1[2].edit_journal("testname3", 5, 465732);
	journal1[3].edit_journal("testname4", 3, 149507);
	journal1[4].edit_journal("testname5", 2, 157202);
	for (int i = 0; i < N; i++)
		journal1[i].print();
	cout << endl;
	Journal journal2("Constructor with param", 4, 354362); //���� ������������ � �����������
	journal2.print();
	cout << endl;
	Journal copy = journal1[3]; //���� ������������ �����������
	copy.print();
	cout << endl;
	journal1[0].sum_journal(journal1[2]); //���� �����
	journal1[0].print();

	
}

