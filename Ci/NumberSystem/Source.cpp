#include <iostream>
#include <vector>
using namespace std;

vector<int> mas;
int irss;

//Переводит символ в число, вместо некорректных символов возвращает -1
int charToInt(char c) {
	if (c >= '0' && c <= '9' && (c - '0') < irss) {
		return c - '0';
	}
	else {
		if (c >= 'A' && c <= 'Z' && (c - 'A') < irss) {
			return c - 'A' + 10;
		}
		else {
			return -1;
		}
	}
}

string st(string str, int ss) {
	irss = ss;
	//Заносит числа исходного числа в вектор
	for (int i = 0; i < str.length(); i++) {
		mas.push_back(charToInt(str[i]));
	}
	return str;
}

//Переводит число в символ
char intToChar(int c) {
	if (c >= 0 && c <= 9) {
		return c + '0';
	}
	else {
		return c + 'A' - 10;
	}
}

//Получает следующую цифру числа в новой системе счисления
int nextNumber(int final) {
	int temp = 0;
	for (int i = 0; i < mas.size(); i++) {
		temp = temp * irss + mas[i];
		mas[i] = temp / final;
		temp = temp % final;
	}
	return temp;
}

//Возвращает true - если массив состоит из одних нулей и false в противном случае
bool zero() {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i] != 0) {
			return false;
		}
	}
	return true;
}

//Конвертирует исходное число в заданную систему счисления
string convertTo(int final) {
	vector<int> b;
	int* arr2{ new int[256] };
	int size = 0;
	do {
		b.push_back(nextNumber(final));
		size++;
	} while (!zero());

	string sTemp = "";
	for (int i = b.size() - 1; i >= 0; i--) {
		sTemp += intToChar(b[i]);
	}
	return sTemp;
}

string sys_10(float number, int system_number, int system_number_in) {
	string str;
	int num = (int) number;
	float ost = number - num;
	int temp = 0;
	int i = 0;
	if (system_number_in < system_number) {
		while (num > 0) {
			temp += (num % 10) * pow(system_number, i);
			//str.insert(str.end(),)
			i++;
		}
	}

	return str;
}



int main() {
	setlocale(LC_ALL, "Russian");
	
	int system_number, system_number_in;
	string origNumber;

	cout << "Введите число: ";
	cin >> origNumber;
	cout << "В какой системе счисления оно? ";
	cin >> system_number;
	cout << "В какую перевести? ";
	cin >> system_number_in;

	st(origNumber, system_number);
	cout << convertTo(system_number_in);

	return 0;
}