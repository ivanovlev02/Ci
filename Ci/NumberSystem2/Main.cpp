#include <iostream>
using namespace std;

int N;
int irss;

int arr_n(int n) {
	int i = 0, k = 0;
	while (n) {
		n /= 10;
		k++;
		i++;
	}
	return i;
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

int my_stoi(string str) {
	int num = 0;
	int ten;
	bool signFlag = true;
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

string st(string str, int ss, int* arr2) {
	irss = ss;
	int n = 0, c = 0;
	int j = 0;
	//n = my_stoi(str);
	//Заносит числа исходного числа в массив
	for (int i = 0; i < str.length(); i++) {
		arr2[i] = charToInt(str[i]);
		//arr2[i] = my_stoi(str);
		//mas.push_back(charToInt(str[i]));
	}
	return str;
}

int v_10(int ss, int *arr, int *arr2) {
	int t = 0;//1010
	          //3210
	int q = 0;
	for (int j = 0; j < N; j++) {
		for (int i = N - 1; i >= 0; i--) {
			arr[j] = arr2[j] * pow(ss, i);
			q = arr[j];
			t = q + (arr2[j+1] * pow(ss, i));
		}
	}
	return t;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	int* arr{ new int[N] };
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
	
	cout << N << endl;
	cout << st(oriNumber, system_number, arr2) << endl;
	cout << v_10(system_number, arr, arr2);

	return 0;
}