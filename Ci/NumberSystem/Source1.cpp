#include <iostream>
using namespace std;

int N;

int arr_n(int n) {
	int i = 0;
	while (n) {
		n /= 10;
		i++;
	}
	return i;
}

//int* arr2{ new int[N] };
int irss;

int my_stoi(string str) {
	int num = 0;
	int ten;
	bool signFlag = true; //true: +, false: -
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			if (i == 0 && str[i] == '-') {
				signFlag = false;
				continue;
			}
			if (i == 0 && str[i] == '+') {
				signFlag = true;
				continue;
			}

			return NULL;
		}

		ten = 1;
		for (unsigned int j = 0; j < str.length() - 1 - i; j++) {
			ten *= 10;
		}

		num += ten * (str[i] - '0');
	}

	if (signFlag) {
		return num;
	}
	else {
		return -num;
	}
}

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

string st(string str, int ss, int *arr2) {
	irss = ss;
	int n = 0, c = 0;
	int j = 0;
	n = my_stoi(str);
	//Заносит числа исходного числа в вектор
	for (int i = 0; i < str.length(); i++) {
		arr2[i] = charToInt(str[i]);
		//mas.push_back(charToInt(str[i]));
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
int nextNumber(int final, int* arr2) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		temp = temp * irss + arr2[i];
		arr2[i] = temp / final;
		temp = temp % final;
	}
	return temp;
}

//Возвращает true - если массив состоит из одних нулей и false в противном случае
bool zero(int* arr2) {
	for (int i = 0; i < N; i++) {
		if (arr2[i] != 0) {
			return false;
		}
	}
	return true;
}

//Конвертирует исходное число в заданную систему счисления
string convertTo(int final, int* arr2) {
	int* arr{ new int[N] };
	int size = 0, i = 0;
	do {
		//b.push_back(nextNumber(final));
		arr[i] = nextNumber(final, arr2);
		size++;
		i++;
	} while (!zero(arr2));

	string sTemp = "";
	for (int i = N - 1; i >= 0; i--) {
		sTemp += intToChar(arr[i]);
	}
	return sTemp;
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	int system_number, system_number_in;
	string oriNumber, number;

	cout << "Введите число: ";
	cin >> oriNumber;
	cout << "В какой системе счисления оно? ";
	cin >> system_number;
	cout << "В какую перевести? ";
	cin >> system_number_in;

	number = oriNumber;
	n = my_stoi(number);
	N = arr_n(n);
	int* arr2{ new int[N] };

	st(oriNumber, system_number, arr2);
	cout << convertTo(system_number_in, arr2);

	return 0;
}