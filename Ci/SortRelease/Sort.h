#pragma once

#include <iostream>
#include <fstream>
#include <time.h>
#include <ctime>

using namespace std;
//const int N = 10000;


static clock_t timer_start_time{ 0 }, timer_stop_time{ 0 };

void start_timer()
{
	timer_start_time = clock();
}

void stop_timer()
{
	timer_stop_time = clock();
	cout << double(timer_stop_time - timer_start_time) /
		CLOCKS_PER_SEC << " sec" << endl;
}

void Peremesh(int* arr) {
	int k = 0;
	while (k != N) {
		for (int i = 0; i < N - 1; i++) {
			k = i + 1;
			for (int j = i + 1; j > 0; j--) {
				int t = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = t;
			}
		}
		k++;
	}
}

void Write_in_array(int* arr, int min, int max) {
	ofstream fin;
	fin.open("output_in.txt");

	if (!fin) {
		cout << "File to write is not open!" << endl;
	}
	else {
		cout << "File to write success open!" << endl;
		srand(time(NULL));
		for (int i = 0; i < N; ++i) {
			arr[i] = rand() % (max - min + 1) + min;
		}

		//Peremesh(arr);

		for (int i = 0; i < N; ++i) {
			fin << arr[i] << endl;
		}
	}
	fin.close();
}

void Selection_Sort(int* arr) {
	int count, key;
	for (int i = 0; i < N - 1; i++) {
		count = arr[i];
		key = i;
		for (int j = i + 1; j < N; j++)
			if (arr[j] < arr[key]) key = j;
		if (key != i) {
			arr[i] = arr[key];
			arr[key] = count;
		}
	}
}

void Buble_Sort(int* arr) {
	int t = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

void Insert_Sort(int* arr) {
	int k, temp = 0;
	for (int i = 0; i < N - 1; i++) {
		k = i + 1;
		temp = arr[k];
		for (int j = i + 1; j > 0; j--) {
			if (temp < arr[j - 1]) {
				arr[j] = arr[j - 1];
				k = j - 1;
			}
		}
		arr[k] = temp;
	}
	/*int k, j = 0;
	for (int i = 2; i < N; i++) {
		k = arr[i];
		j = i;
		while(j > 1 && arr[j-1] > k) {
				arr[j] = arr[j - 1];
				j = j - 1;
		}
		arr[j-1] = k;
	}*/
}

void Shake_Sort(int* arr) {
	int t = 0;
	int s = 0;
	int right = 0;
	int left = (N - 1);
	while (right < left) {
		for (int i = right; i < left; i++) {
			if (arr[i] > arr[i + 1]) {
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
			}
		}
		left--;
		for (int j = left; j > right; j--) {
			if (arr[j] < arr[j - 1]) {
				s = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = s;
			}
		}
		right++;
	}
}

void Quick(int* arr, int nstart, int nend) {
	int l, r, c, x;
	l = nstart;
	r = nend;
	x = arr[(l + r) / 2];
	do {
		while (arr[l] < x) l++;
		while (arr[r] > x) r--;
		if (l <= r) {
			int g = arr[l];
			arr[l] = arr[r];
			arr[r] = g;
			l++;
			r--;
		}
	} while (l <= r);
	if (nstart < r) Quick(arr, nstart, r);
	if (l < nend) Quick(arr, l, nend);
}

void heap(int* arr, int n, int i)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[max])
		max = left;

	if (right < n && arr[right] > arr[max])
		max = right;

	if (max != i)
	{
		int s = arr[i];
		arr[i] = arr[max];
		arr[max] = s;

		heap(arr, n, max);
	}
}

void heapSort(int* arr, int n)
{
	int i = n / 2 - 1;
	int j = n - 1;

	while (i >= 0) {
		heap(arr, n, i);
		i--;
	}
	while (j >= 0) {
		int q = arr[0];
		arr[0] = arr[j];
		arr[j] = q;

		heap(arr, j, 0);
		j--;
	}
}