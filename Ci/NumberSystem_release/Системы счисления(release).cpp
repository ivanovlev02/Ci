#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

int N;

char digitt(int num) {
	string a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return a[num];
}

int digits(char num) {
	string a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == num) return i;
	}
}

int digit_int(char n) {
	switch (n) {
	case '.': return 46;
	case 48: return 0;
	case 49: return 1;
	case 50: return 2;
	case 51: return 3;
	case 52: return 4;
	case 53: return 5;
	case 54: return 6;
	case 55: return 7;
	case 56: return 8;
	case 57: return 9;
	}
}

double string_double(string s) {
	int i, l = s.length(), k = 1;
	double r = 0, p = 1;
	for (i = 0; i < l; i++) {
		if (k < 0) p = p * 10;
		if (s[i] == '.')
			k = -k;
		else
			r = r * 10 + (s[i] - '0');
	}
	return r / p;
}

long long int _10_ss_int(int* arr, int n, int ss) {
	long long int num, num4 = 0, num3 = 0;
	num = n - 1;//9-1=8

	for (int i = 0; i < n; i++) {
		num3 = arr[i] * pow(ss, num);
		num4 = num4 + num3;
		num--;
	}

	return num4;
}


double _10_ss_double(string a, int* arr, int ss) {
	int num, num4 = 0, n = 0;
	num = N - 1;//9-1=8
	double num2 = 0, num3, num5, num6 = 0, num7 = 0, num8 = 0, num9 = 0;
	num2 = string_double(a);
	n = num2;
	num3 = num2 - (int)num2;

	num7 = num3;
	for (int i = -1; i > -N; i--) {
		num7 = (num7 - (int)num7) * 10;
		num5 = (int)num7 * pow(ss, i);
		num6 = num6 + num5;
	}
	return num6;
}

//В десятичную
double _10_SS(string a, int* arr, int ss) {//AB32C.1B6,10 11 3 2 12 46 1 11 6, 16
	int num, num4 = 0, n = 0;
	num = N - 1;//9-1=8
	double num2 = 0, num3, num5, num6 = 0, num7 = 0, num8 = 0, num9 = 0;
	num2 = string_double(a);
	cout << "num2 = " << num2 << endl;
	n = num2;
	num3 = num2 - (int)num2;
	int* arr2{ new int[N] };

	for (int i = 0; i < N; i++) {
		if (arr[i] >= 10) {
			for (int i = 0; i < N; i++) {
				arr[i] = arr[i] * pow(ss, num);
				num4 = num4 + arr[i];
				num--;
			}
			return num4;
		}
		else {
			num7 = num3;
			for (int i = -1; i > -N; i--) {
				num7 = (num7 - (int)num7) * 10;
				num5 = (int)num7 * pow(ss, i);
				num6 = num6 + num5;
			}
			int c = n;
			for (int i = 0; i < N - 1; i++) {
				n = c % 10;
				num4 = n * pow(ss, i);
				num8 = num8 + num4;
				c = c / 10;
			}
			num9 = num8 + num6;
			return num9;
		}
	}
}

//------------------Из десятичной в любую-----------------------\\
//целая часть числа
int cel_number(int a, int p, char* s) {
	int num = (int)a;
	int rest = num % p;
	num /= p;
	if (num == 0) { s[0] = digitt(rest); return 1; }
	int k = cel_number(num, p, s);
	s[k++] = digitt(rest);
	return k;
}

//дробная часть
void drob_number(double a, int p, char* s) {
	int i = 0, k = 0;
	double a1 = a;
	do {
		a1 = a1 * p;
		int num = (int)(a1);
		s[k++] = digitt(num);
		a1 -= (int)a1;
		i++;
	} while (a1 > 0.00000001 && i < 10);
	s[k] = '\0';
}
//из буквы в цифру
int returnVal(char x)
{
	return (int)x - 55;
}

int main() {
	setlocale(LC_ALL, "Rus");

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 300, 300, TRUE); // 800 width, 100 height


	bool flag = false;
	double number = 0, n;
	string aa, ab;
	char point = '.';
	char s[80] = { 0 };
	int p, q, w = 0, n_out2 = 0, n_out1 = 0;
	double number1 = 0, number2 = 0, number3 = 0;
	int d = 0;

	cout << "Введите число: ";
	getline(cin, aa);//AB32C.1B6
	N = aa.length();//9
	//cout << N << endl;
	cout << "В какой СС оно: ";
	cin >> q;
	cout << "В какую перевести: ";
	cin >> p;

	ab = aa;//AB32C.1B6
	int* arr{ new int[N] };
	int* arr2{ new int[N] };
	int* arr3{ new int[N] };

	for (int i = 0; i < aa.length(); i++) {
		if ((aa[i] >= 'A' && aa[i] <= 'Z') || (aa[i] >= 'a' && aa[i] <= 'z')) {
			arr[i] = digits(aa[i]);
		}
		else {
			arr[i] = digit_int(aa[i]);
		}
		if (arr[i] == 46) {
			flag = true;
			w = i;
		}
		//cout << arr[i] << " ";
	}
	arr2 = arr;
	cout << endl;

	if (flag == true) {
		while (arr2[d] != 46) {
			n_out1 = d;
			d++;
		}

		w = w + 1;
		for (int i = 0; i < N; i++) arr3[i] = 0;
		int chislo = 0;
		chislo = chislo - (N - w);
		arr3 = arr;
		for (int i = -1; i > chislo - 1; i--) {
			number1 = arr3[w] * pow(q, i);
			number2 = number2 + number1;
			w++;
		}
		number3 = _10_ss_int(arr2, d, q);
		number = number3 + number2;
		if (q == 10) {
			cout.precision(15);
			cout << "number= " << number << endl;
		}
		q = 10;
	}
	if (q == 10) {
		int k = cel_number((int)number, p, s);
		s[k++] = ',';
		drob_number(number - (int)number, p, &s[k]);
		cout << "Результат = " << s << endl;
	}
	_getch();
	return 0;
}
