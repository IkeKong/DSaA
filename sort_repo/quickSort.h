#pragma once

template<typename T>
void __quickSortD(T arr[], int left, int right) {
	if (left >= right)
		return;

	T v = arr[left];

	// [left+1, l] store less or equal v member
	int l = left;
	for (int i = left+1; i <= right; i++) {
		if (arr[i] > v)
			continue;
		else {
			swap(arr[l + 1], arr[i]);
			l++;
		}
	}
	swap(arr[left], arr[l]);

	__quickSortD(arr, left, l - 1);
	__quickSortD(arr, l + 1, right);
	return;
}

template<typename T>
void quickSortDirected(T arr[], int n) {
	__quickSortD(arr, 0, n - 1);
	return;
}

