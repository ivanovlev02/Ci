#include <iostream>
#include <string>
using namespace std;

int texte(string text, string templ) {
	int d[256];
	int i, j, k, N, M;
	N = text.length();
	M = templ.length();
	for (i = 0; i < 256; i++) //запись в 256 ячеек количество символов текста
		d[i] = M;
	cout << "shift" << endl;
	for (i = 0; i < M - 1; i++) {
		d[templ[i]] = M - i - 1; //шаблон - 1
		cout << templ[i] << " = " << d[templ[i]] << endl;
	}
		

	i = 0;
	while (i + M - 1 < N) {
		k = i + M - 1; // подсчет ходов, до такого же первого символа в шаблоне
		j = M - 1;
		while (j >= 0 && text[k] == templ[j]) {
			k--;
			j--;
		}
		if (j < 0) return i;
		i += d[text[i + M - 1]];
	}
	return -1;
}

int main() {
	string text;
	string templ;
	string templ2;

	getline(cin, text);
	getline(cin, templ);

	cout << texte(text, templ) << endl;

	/*for (int i = 0; i < (text.length()/text.length()); i++) {
		for (int j = 0; j < (templ.length()/templ.length()); j++) {
			if (text[i] == templ[j]) {
				k++;
			}
			if (text[i] != templ[j]) {
				text[i] = text[i + 1];
			}
		}
	}*/
	return 0;
}