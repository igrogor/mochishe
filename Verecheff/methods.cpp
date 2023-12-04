#include "Header.h"

///////////////////////////////////////////////////////////////////////////// Integer

int Integer::changeNum() {
	return NULL;
}

char* Integer::getNum() {
	return nullptr;
}
/*


������������


*/
IntegerM::IntegerM() {
	this->num = new char[2];
	this->num[0] = '0';
	this->num[1] = '\0';
	this->arrayLenght = 1;
}

IntegerM::IntegerM(char* num) { 
	this->arrayLenght = countLenght(num);
	this->num = new char[this->arrayLenght + 1];

	for (int i = 0; num[i] != '\0'; i++) {
		this->num[i] = num[i];
	}

	this->num[this->arrayLenght] = '\0';
}

IntegerM::IntegerM(const IntegerM& integer) {
	this->arrayLenght = integer.arrayLenght;
	this->num = new char[arrayLenght + 1];
	int i;
	for (i = 0; integer.num[i] != '\0'; i++) {
		this->num[i] = integer.num[i];
	}
	this->num[i] = integer.num[i];
}

/*


������������� ���������


*/
IntegerM IntegerM::operator+(const IntegerM& integer)const{ 
	IntegerM a = *this;
	IntegerM b = integer;
	int one = (int) a;
	int two = (int) b;
	int res = one + two;
	bool minus = false;

	if (res < 0) {
		minus = true;
		res *= -1;
	}

	int size = 0;
	char* str = new char[size + 1];

	if (res != 0) {
		for (int i = 1; res > 0; i++) {
			str[size++] = '0' + res % 10;
			res /= 10;

			char* buf = new char[size + 1];
			for (int k = 0; k < size; k++) {
				buf[k] = str[k];
			}
			delete[] str;
			str = buf;
		}
	}
	else {
		str[0] = '0';
		size++;
	}

	char* readyStr = new char[size + 1];
	int i, k = size;
	if (minus) {
		size++;
		readyStr[0] = '-';
		i = 1;
	}
	else i = 0;

	for (; i < size; i++, k--) {
		readyStr[i] = str[k - 1];
	}
	delete[] str;
	readyStr[size] = '\0';

	IntegerM result(readyStr);
	return result;
}

IntegerM &IntegerM::operator++()  {
	char* c = new char[2];
	c[0] = '1';
	c[1] = '\0';
	IntegerM one(c);
	*this = *this + one;
	delete[] c;

	return *this;
}

IntegerM IntegerM::operator++(int) {
	IntegerM buf = *this;
	++(*this);
	return buf;
}

IntegerM &IntegerM::operator=(const IntegerM& integer)  {
	if (&integer == this) return *this;
	if(this->num) delete[] this->num;
	if (integer.num) {
		this->num = new char[integer.arrayLenght + 1];
		this->arrayLenght = integer.arrayLenght;

		for (int i = 0; i < integer.arrayLenght + 1; i++) {
			this->num[i] = integer.num[i];
		}
	}
	else {
		this->num = new char[2];
		this->num[0] = '0';
		this->num[1] = '\0';
		this->arrayLenght = 1;
	}
	return *this;
}

IntegerM::operator int(){
	int result = 0;
	char* p;

	p = &this->num[this->arrayLenght - 1];

	for (int i = 1; p >= this->num; i *= 10, p--) {
		if (*p == '-') {
			result *= -1;
			break;
		}
		result += (*p - 48) * i;
	}

	return result;
}

IntegerM operator-(const IntegerM& obj1, const IntegerM& obj2) {
	IntegerM a = obj1;
	IntegerM b = obj2;
	int one = (int)a;
	int two = (int)b;
	int res = one - two;
	bool minus = false;

	if (res < 0) {
		minus = true;
		res *= -1;
	}

	int size = 0;
	char* str = new char[size + 1];

	if (res != 0) {
		for (int i = 1; res > 0; i++) {
			str[size++] = '0' + res % 10;
			res /= 10;

			char* buf = new char[size + 1];
			for (int k = 0; k < size; k++) {
				buf[k] = str[k];
			}
			delete[] str;
			str = buf;
		}
	}
	else {
		str[0] = '0';
		size++;
	}

	char* readyStr = new char[size + 1];
	int i, k = size;
	if (minus) {
		size++;
		readyStr[0] = '-';
		i = 1;
	}
	else i = 0;

	for (; i < size; i++, k--) {
		readyStr[i] = str[k - 1];
	}
	delete[] str;
	readyStr[size] = '\0';

	IntegerM result(readyStr);
	return result;
}

istream& operator>>(istream& in, IntegerM& obj) {
	int size;
	delete[] obj.num;

	in.read((char*) &size, sizeof(int));
	obj.num = new char[size + 1];
	in.read(obj.num, size);

	obj.num[size] = '\0';
	
	obj.arrayLenght = size;

	return in;
}

ostream& operator<<(ostream& out, IntegerM& obj){
	ofstream bin;
	bin.open("binFile.bin", ofstream::binary);

	if (bin.is_open()) {
		bin.write((char*) &obj.arrayLenght, sizeof(int));
		bin.write(obj.num, obj.arrayLenght + 1);
		cout << "\n����� ���� �������/��������" << endl;
	}
	else cout << "\n����� �� ���� �������" << endl;

	bin.close();

	out << obj.arrayLenght << obj.num;

	return out;
}

/*


������ ������


*/
int IntegerM::changeNum() { 
	cout << "������� ����� �����: ";
	this->num = NULL;
	char c;
	int size = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (!isdigit(c) && c != '-') { //�������� ����, ��� �������� ����� 
			printf("������ �����. ������� �����, ���������� ����� �� 0 �� 9 � ���� -\n");
			delete[] this->num;
			exit(NULL);  //��������� ��������� � ������ ������
		}

		char* tempNum = new char[size + 1];
		tempNum[size++] = c;

		for (int i = 0; i < size - 1; i++) {
			tempNum[i] = this->num[i];
		}

		delete[] this->num;
		this->num = tempNum;
	}
	char* tempNum = new char[size + 1];
	tempNum[size++] = '\0';

	for (int i = 0; i < size - 1; i++) {
		tempNum[i] = this->num[i];
	}

	delete[] this->num;
	this->num = tempNum;

	this->arrayLenght = countLenght(this->num);
	return 1;
}

int IntegerM::countLenght(char* num) { 
	int count = 0;
	while (*num != '\0') {
		num++;
		count++;
	}
	return count;
} 

char* IntegerM::getNum() {
	return this->num;
}

int IntegerM::getLenght() {
	return this->arrayLenght;
}

//����������
IntegerM::~IntegerM() { 
	delete[] num;
}

///////////////////////////////////////////////////////////////////////////// IntegerMod

IntegerMod::IntegerMod() {
	this->negNum = false;
}

IntegerMod::IntegerMod(char* num) : IntegerM(num){
	if (this->num[0] == '-') this->negNum = true;
	else this->negNum = false;
}

IntegerMod::IntegerMod(const IntegerMod& integer) : IntegerM(integer) {
	this->negNum = integer.negNum;
}

IntegerMod& IntegerMod::operator= (const IntegerMod& integer){
	if (&integer == this) return *this;
	if(integer.num) this->negNum = integer.negNum;
	IntegerM::operator= (integer);
	return *this;
}

bool IntegerMod::getNegNum() {
	return this->negNum;
}

char* IntegerMod::getNum() {
	char* result = new char[this->arrayLenght + 2];

	for (int i = 0; i < arrayLenght; i++) {
		result[i] = this->num[i];
	}
	
	char c = '0';
	if (this->negNum) c = '1';
	result[this->arrayLenght] = c;
	result[arrayLenght + 1] = '\0';
	return result;
}

int IntegerMod::changeNum(){
	IntegerM::changeNum();
	if (this->num[0] == '-') this->negNum = true;
	else this->negNum = false;
	return 0;
}

///////////////////////////////////////////////////////////////////////////// Deque

//������������
Deque::Deque() {
	point_begin = nullptr;
	point_end = nullptr;
	point_current = nullptr;
	countElements = NULL;
	currentID = 0;
}

Deque::Deque(int count, ...) {
	point_begin = new Node;
	point_end = new Node;
	point_current = point_begin;
	countElements = count;
	currentID = 0;

	va_list args;
	va_start(args, count);
	IntegerM* obj = va_arg(args, IntegerM*);
	point_end = first(obj++);

	for (int i = 1; i < count; i++) {
		obj = va_arg(args, IntegerM*);
		add(obj);
	}
	point_end->next = nullptr;
}

Deque::Deque(const Deque& store) {
	point_begin = new Node;
	point_end = new Node;
	point_current = point_begin;
	countElements = store.countElements;
	currentID = 0;

	Node* point = store.point_begin;
	IntegerM* obj = point->obj;
	point_end = first(obj);
	point = point->next;

	for (int i = 1; i < store.countElements; i++) {
		obj = point->obj;
		add(obj);
		point = point->next;
	}
	point_end->next = nullptr;
}

//������ ����������
Deque::Node* Deque::first(IntegerM* obj) {
	currentID = 1;
	point_begin->obj = obj;
	point_begin->prev = nullptr;
	point_begin->id = currentID++;

	return point_begin;
}

void Deque::add(IntegerM* obj) {
	Node* newNode = new Node;
	point_end->next = newNode;
	newNode->obj = obj;
	newNode->prev = point_end;
	newNode->id = currentID++;
	point_end = newNode;
}

void Deque::pasteElement(int id, IntegerM* obj) {
	point_current = search(id);
	if  (point_current != nullptr) {
		Node* newNode = new Node;
		newNode->obj = obj;
		newNode->prev = point_current->prev;
		newNode->id = point_current->id;
		newNode->next = point_current;
		point_current->prev->next = newNode;
		point_current->prev = newNode;
		countElements++;
		for (int i = id; i < countElements; i++) {
			point_current->id++;
			point_current = point_current->next;
		}
	}
	else cout << "\n�� ������� �������� �������." << endl;
}

//������ ������
IntegerM* Deque::readLeft() {
	IntegerM* obj = point_current->obj;
	point_current = point_current->next;
	return obj;
}

IntegerM* Deque::readRight() {
	IntegerM* obj = point_current->obj;
	point_current = point_current->prev;
	return obj;
}

IntegerM* Deque::sampleLeft(){
	IntegerM* obj = point_begin->obj;
	deleteLeftNode();
	return obj;
}

IntegerM* Deque::sampleRight() {
	IntegerM* obj = point_end->obj;
	deleteRightNode();
	return obj;
}

Deque::Node* Deque::search(int id) {
	point_current = point_begin;
	if (id > countElements || id == 0) {
		cout << "������� �������� ����� �������� � �������" << endl;
		return nullptr;
	}
	for (int i = 0; point_current != nullptr && id != point_current->id; i++) point_current = point_current->next;
	if (id == point_current->id) return point_current;
	return nullptr;
}

Deque::Node* Deque::search(IntegerM* obj) {
	point_current = point_begin;
	int lenghtOne = obj->getLenght();
	bool check = false;
	for (int i = 0; point_current != nullptr && check != true; i++) {
		int lenghtTwo = point_current->obj->getLenght();
		bool coincidence = true;
		for (int j = 0; j < lenghtOne && j < lenghtTwo && lenghtTwo == lenghtOne; j++) {
			if (obj->getNum()[j] == '-' && point_current->obj->getNum()[j] == '-') j++;

			if (obj->getNum()[j] != point_current->obj->getNum()[j]) {
				coincidence = false;
				break;
			}
		}
		if (lenghtTwo != lenghtOne) coincidence = false;
		if (coincidence == true) return point_current;
		point_current = point_current->next;
	}
	if (check == false) cout << "\n�������� �� ���� �������." << endl;
	else return point_current;

	return nullptr;
}

void Deque::outputElements(IntegerM* (Deque::*func)()) {
	if (point_end == nullptr || point_begin == nullptr) {
		cout << "���� �� ������." << endl;
		exit(NULL);
	}

	cout << "\n���������� ��������: " << endl;

	if (func == &Deque::readLeft || func == &Deque::sampleLeft) point_current = point_begin;
	else point_current = point_end;

	int buf = countElements;

	while(countElements != 0 ) {
		IntegerM* check = (IntegerM*) (this->*func)();
		cout << check->getNum() << endl;
		if (func == &Deque::readLeft || func == &Deque::readRight) countElements--;
	}

	if (func == &Deque::readLeft || func == &Deque::readRight) countElements = buf;
}

IntegerM* Deque::outputElementByID(int id) {
	if (search(id) != nullptr) {
		IntegerM* p = (IntegerM*)point_current->obj;
		cout << "\n������� � ������� " << id << ": " << p->getNum() << endl;
		return point_current->obj;
	}
	return nullptr;
}

int Deque::outputElementByMean(IntegerM* searchObj) {
	if (search(searchObj) != nullptr) {
		cout << "\n������� �� ��������� " << searchObj->getNum() << " ����� � ������ �����: " << point_current->id << endl;
		return point_current->id;
	}
	return NULL;
}

//������ ��������
void Deque::deleteLeftNode() {
	if (point_begin != point_end) {
		point_begin = point_begin->next;
		delete point_begin->prev;
		point_begin->prev = nullptr;
	}
	else {
		delete point_begin;
		point_end = nullptr;
		point_begin = nullptr;
	}
	countElements--;
}

void Deque::deleteRightNode() {
	if (point_begin != point_end) {
		point_end = point_end->prev;
		delete point_end->next;
		point_end->next = nullptr;
	}
	else {
		delete point_end;
		point_end = nullptr;
		point_begin = nullptr;
	}
	countElements--;
}

void Deque::del(int id) {
	point_current = search(id);
	if (point_current != nullptr) {
		point_current->prev->next = point_current->next;
		point_current->next->prev = point_current->prev;
		Node* buf = new Node;
		buf = point_current->next;
		delete point_current;
		point_current = buf;
		countElements--;
		for (int i = id; i <= countElements; i++) {
			point_current->id--;
			point_current = point_current->next;
		}
	}
	else cout << "\n�� ������� ������� �������." << endl;
}

//������� � �������
Deque::Node* Deque::getPointBegin(){
	return this->point_begin;
}

Deque::Node* Deque::getPointEnd(){
	return this->point_end;
}

int Deque::getCountElements(){
	return this->countElements;
}

void Deque::setPoint(Node* point) {
	this->point_current = point;
}

//����������
Deque:: ~Deque() {
	delete point_begin, point_end, point_current;
}
