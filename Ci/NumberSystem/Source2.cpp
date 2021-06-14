#include <iostream>
using namespace std;

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

int digit_l(char letter) {
	switch (letter) {
	case 'A': return 10;//A
	case 'B': return 11;//B
	case 'C': return 12;//C
	case 'D': return 13;//D
	case 'E': return 14;//E
	case 'F': return 15;//F
	case 'G': return 16;//G
	case 'H': return 17;//H
	case 'I': return 18;//I
	case 'J': return 19;//J
	case 'K': return 20;//K
	case 'L': return 21;//L
	case 'M': return 22;//M
	case 'N': return 23;//N
	case 'O': return 24;//O
	case 'P': return 25;//P
	case 'Q': return 26;//Q
	case 'R': return 27;//R
	case 'S': return 28;//S
	case 'T': return 29;//T
	case 'U': return 30;//U
	case 'V': return 31;//V
	case 'W': return 32;//W
	case 'X': return 33;//X
	case 'Y': return 34;//Y
	case 'Z': return 35;//Z
	}
}

//В десятичную
int _10_SS(int num, int ss) {
	int num2, num3, num4 = 0, ss_in;
	int i = 0, j = 0;
	num3 = num;
	while (num) {
		num2 = num % 10;
		num /= 10;
		i++;
	}
	int* arr{ new int[i] };
	while (num3) {
		num2 = num3 % 10;
		arr[j] = num2;
		num3 /= 10;
		j++;
	}
	for (int k = 0; k < i; k++) {
		arr[k] = arr[k] * pow(ss, k);
		num4 = num4 + arr[k];
	}

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

int main() {
	setlocale(LC_ALL, "Rus");
	double a;
	string aa;
	char s[80] = { 0 };
	int p, q;

	cout << "Введите число в 10-сс: ";
	cin >> a;
	cout << "В какой СС оно: ";
	cin >> q;
	cout << "В какую перевести: ";
	cin >> p;

	int k = cel_number((int)a, p, s);
	s[k++] = ',';
	drob_number(a - (int)a, p, &s[k]);
	cout << s;
	//cout << _10_SS(a, q);

	//cout << _10_SS(a, q);

	return 0;
}