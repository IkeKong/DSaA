#pragma once
#include <iostream>

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
	if (arr == NULL || n <= 0)
		return;

	// [0, i) contains ordered nums
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;	// record minist member's index
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_index])
				min_index = j;
		}
		swap(arr[i], arr[min_index]);
	}

	return;
}







