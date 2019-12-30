#pragma once

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n) {
	if (arr == NULL || n <= 0)
		return;

	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
	return;
}
