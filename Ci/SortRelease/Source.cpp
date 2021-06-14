#define N 10000
#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>
#include "Sort.h"
using namespace std;

int menu() {
	int count = { 0 };
	cout << "1. Insert\n" << "2. Select\n" << "3. Shake\n" << "4. Buble\n" << "5. Quick\n" << "6. Heap\n" << "7. Exit\n\n";
	cin >> count;
	return count;
}

int main() {
	int* arr;
	int* arr2;
	int* arr3;
	int* arr4;
	int* arr5;
	int* arr6;
	arr = new int[N];
	arr2 = new int[N];
	arr3 = new int[N];
	arr4 = new int[N];
	arr5 = new int[N];
	arr6 = new int[N];
	int k = 0;
	int length = k;
	int min = 0;
	int max = 1000;
	double schit;
	double schit2;

	//Write_in_array(arr, min, max);

	ifstream fin;
	fin.open("output_in.txt");

	ofstream fout;
	fout.open("output_out.txt");
	ofstream fout_2;
	fout_2.open("output_out_2.txt");
	ofstream fout_3;
	fout_3.open("output_out_3.txt");
	ofstream fout_4;
	fout_4.open("output_out_4.txt");
	ofstream fout_5;
	fout_5.open("output_out_5.txt");
	ofstream fout_6;
	fout_6.open("output_out_6.txt");

	while ((!fin.eof()) && (k != N)) {
		fin >> schit;
		arr[k] = schit;
		arr2[k] = schit;
		arr3[k] = schit;
		arr4[k] = schit;
		arr5[k] = schit;
		arr6[k] = schit;
		k++;
	}

	cout << "Amount of numbers: " << k << endl << endl;
	
	/*for (int i = 0; i < N; ++i) {
		fout << arr[i] << endl;
		fout_2 << arr2[i] << endl;
		fout_3 << arr3[i] << endl;
		fout_4 << arr4[i] << endl;
		fout_5 << arr5[i] << endl;
		fout_6 << arr6[i] << endl;
	}*/
	
	int count;
	do {
		count = menu();
		switch (count) {
		case 0: {
			for (int i = 0; i < N; ++i) {
				fout << arr[i] << endl;
				fout_2 << arr2[i] << endl;
				fout_3 << arr3[i] << endl;
				fout_4 << arr4[i] << endl;
				fout_5 << arr5[i] << endl;
				fout_6 << arr6[i] << endl;
			}
			break;
		}
		case 1: {
			start_timer();
			Insert_Sort(arr);
			stop_timer();
			for (int i = 0; i < N; ++i) {
				fout << arr[i] << endl;
			}
			cout << endl;
			break;
		}
		case 2: {
			start_timer();
			Selection_Sort(arr2);
			stop_timer();
			for (int i = 0; i < N; ++i) {
				fout_2 << arr2[i] << endl;
			}
			cout << endl;
			break;
		}
		case 3: {
			start_timer();
			Shake_Sort(arr3);
			stop_timer();
			for (int i = 0; i < N; ++i) {
				fout_3 << arr3[i] << endl;
			}
			cout << endl;
			break;
		}
		case 4: {
			start_timer();
			Buble_Sort(arr4);
			stop_timer();
			for (int i = 0; i < N; ++i) {
				fout_4 << arr4[i] << endl;
			}
			cout << endl;
			break;
		}
		case 5: {
			start_timer();
			Quick(arr5, 0, N - 1);
			stop_timer();
			for (int i = 0; i < N; ++i) {
				fout_5 << arr5[i] << endl;
			}
			cout << endl;
			break;
		}
		case 6: {
			start_timer();
			heapSort(arr6, N);
			stop_timer();
			for (int i = 0; i < N; ++i) {
				fout_6 << arr6[i] << endl;
			}
			cout << endl;
			break;
		}
		case 7: {
			cout << "Exit";
			exit(EXIT_SUCCESS);
			break;
		}
		default: {
			cout << "Error";
			exit(EXIT_FAILURE);
			break;
		}
		}
	}while (count != 7);

	fin.close();
	fout.close();
	fout_2.close();
	fout_3.close();
	fout_4.close();
	fout_5.close();
	fout_6.close();
	delete[]arr;
	delete[]arr2;
	delete[]arr3;
	delete[]arr4;
	delete[]arr5;
	delete[]arr6;

	return 0;
}

/*
Итог
Selection: 9.689 sec
Buble: 39.849 sec
Insert: 10.03 sec
Shake: 22.55 sec
Quick: 0.01 sec
Heap: 0.048 sec
*/
/*1 000 000
1 - 1128.19 sec
2 - 1022.23 sec
3 - 2510.34 sec
4 - 5808.16 sec
5 - 0.106 sec
6 - 0.616 sec
*/