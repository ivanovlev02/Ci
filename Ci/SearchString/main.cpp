#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int seek(string s, string q) {
	int d[256], dd = 0;
	int i, j, k, N, M;
	N = s.length();
	M = q.length();
	for (i = 0; i < 256; i++) d[i] = M;

	for (i = 0; i < M - 1; i++) d[q[i]] = M - i - 1;
	i = 1;
	while (i + M - 1 < N) {
		k = i + M - 1;
		j = M - 1;
		while (j >= 0 && s[k] == q[j]) {
			k--;
			j--;
		}
		if (j < 0) return i;
		i += d[s[i + M - 1]];
		cout << i << endl;
	}
	return -1;
}

void got(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
	string s, q;
	getline(cin, s);
	getline(cin, q);

	got(seek(s, q), 1);
	cout << q;
	
	return 0;
}