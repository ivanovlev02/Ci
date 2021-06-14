#include <iostream>
using namespace std;
const int Ni = 20;
const int Nj = 20;

int main() {
	int N;
	int arr[Ni][Nj];

	for (int i = 0; i < Ni; i++) {
		for (int j = 0; j <= i; j++) {
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < Ni; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	for (int i = 0; i < Ni; i++) {
		for (int j = 0; j <= i; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}