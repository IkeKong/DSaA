#pragma once

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

template<typename T>
T* copyArray(T arr[], int n) {
	if (arr == NULL || n <= 0)
		return NULL;
	T* ret = new T[n];
	for (int i = 0; i < n; i++) {
		ret[i] = arr[i];
	}

	return ret;
}

template<typename T>
T* genNearlyOrderedArr(int n, int unorder_num) {
	assert(n > 0);
	T* arr = new T[n];
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}

	srand(time(NULL));

	for (int i = 0; i < unorder_num / 2; i++) {
		int a = rand() % n;
		int b = rand() % n;
		swap(arr[a], arr[b]);
	}

	return arr;
}

template<typename T>
T* generateRandomArray(int n, int left, int right) {
	assert(n > 0);
	srand(time(NULL));
	T* arr = new T[n];

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (right - left + 1) + left;
	}

	return arr;
}

template<typename T>
void printArray(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return;
}

template<typename T>
bool isSorted(T arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

template<typename T>
void testSort(T arr[], int n, string sort_name,void(*sortFunc)(T[], int)) {
	clock_t start_time = clock();
	sortFunc(arr, n);
	clock_t end_time = clock();
	// printArray(arr, n);
	assert(isSorted(arr, n));

	double seconds = double(end_time - start_time) / CLOCKS_PER_SEC;
	cout << "using " << sort_name << " :" << seconds << " seconds." << endl;
	// printArray(arr, n);
	return;
}


