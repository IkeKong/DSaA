#pragma once

using namespace std;

template<typename T>
void shellSort(T arr[], int n) {
	if (arr == NULL || n <= 0)
		return;

	int h = 1;
	while (h < n / 3) {
		h = h * 3 + 1;
	}

	while (h >= 1) {
		for (int i = h; i < n; i++) {
			for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) {
				swap(arr[j], arr[j - h]);
			}
		}
		h /= 3;
	}
	
	return;
}
