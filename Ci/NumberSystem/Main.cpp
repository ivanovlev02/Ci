#include <iostream>
#include <string>
using namespace std;

int N;

char digit(int num) {
	switch (num) {
	case 0: return 48;//0
	case 1: return 49;//1
	case 2: return 50;//2
	case 3: return 51;//3
	case 4: return 52;//4
	case 5: return 53;//5
	case 6: return 54;//6
	case 7: return 55;//7
	case 8: return 56;//8
	case 9: return 57;//9
	case 10: return 65;//A
	case 11: return 66;//B
	case 12: return 67;//C
	case 13: return 68;//D
	case 14: return 69;//E
	case 15: return 70;//F
	case 16: return 71;//G
	case 17: return 72;//H
	case 18: return 73;//I
	case 19: return 74;//J
	case 20: return 75;//K
	case 21: return 76;//L
	case 22: return 77;//M
	case 23: return 78;//N
	case 24: return 79;//O
	case 25: return 80;//P
	case 26: return 81;//Q
	case 27: return 82;//R
	case 28: return 83;//S
	case 29: return 84;//T
	case 30: return 85;//U
	case 31: return 86;//V
	case 32: return 87;//W
	case 33: return 88;//X
	case 34: return 89;//Y
	case 35: return 90;//Z
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

//В десятичную
int _10_SS(string a, int *arr, int ss) {
	int num, num4 = 0;
	num = N - 1;
	double num2 = 0, num3, num5;
	num2 = string_double(a);
	num3 = num2 - (int)num2;
	int* arr2{ new int[N] };
	for (int i = -N; i < -1; i++) {
		num5 = num3 / ss;
		arr2[i] = (int)num5;
	}
	/*for (int i = 0; i < N; i++) {
		arr[i] = arr[i] * pow(ss, num);
		num4 = num4 + arr[i];
		num--;
	}*/

	return num4;
}

//------------------Из десятичной в любую-----------------------\\
//целая часть числа
int cel_number(int a, int p, char* s) {
	int num = (int)a;
	int rest = num % p;
	num /= p;
	if (num == 0) { s[0] = digit(rest); return 1; }
	int k = cel_number(num, p, s);
	s[k++] = digit(rest);
	return k;
}

//дробная часть
void drob_number(double a, int p, char* s) {
	int i = 0, k = 0;
	double a1 = a;
	do {
		a1 = a1 * p;
		int num = (int)(a1);
		s[k++] = digit(num);
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
	double number, n;
	string aa, ab;
	char point = '.';
	char s[80] = { 0 };
	int p, q;

	cout << "Введите число в 10-сс: ";
	getline(cin, aa);
	N = aa.length();
	cout << "В какой СС оно: ";
	cin >> q;
	cout << "В какую перевести: ";
	cin >> p;

	ab = aa;
	int* arr{ new int[N] };
	int* arr2{ new int[N] };

	for (int i = 0; i < aa.length(); i++) {
		if ((aa[i] >= 'A' && aa[i] <= 'Z') || (aa[i] >= 'a' && aa[i] <= 'z')) {
			arr[i] = returnVal(aa[i]);
		}
		else {
			arr[i] = digit_int(aa[i]);
		}
		//cout << arr[i] << " ";
	}
	
	if (q == 10) {
		n = string_double(ab);
		int k = cel_number((int)n, p, s);
		s[k++] = ',';
		drob_number(n - (int)n, p, &s[k]);
		cout << s;
	}
	else {
		n = _10_SS(ab,arr, q);
		int k = cel_number((int)n, p, s);
		s[k++] = ',';
		drob_number(n - (int)n, p, &s[k]);
		cout << s;
	}
	
	
	return 0;
}