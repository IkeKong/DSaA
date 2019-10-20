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

template<typename T>
void __quickSortBD(T arr[], int left, int right) {
	if (left >= right)
		return;
	T v = arr[left];
	// [left+1, i] contains less or equal v members
	// [j, right] contains members bigger than v 
	
	int i = left, j = right + 1;
	for (int k = left + 1; k < j; k++) {
		if (arr[k] > v) {
			swap(arr[k], arr[j - 1]);
			k--;
			j--;
		}
		else
			i++;
	}
	swap(arr[i], arr[left]);

	__quickSortBD(arr, left, i - 1);
	__quickSortBD(arr, i + 1, right);
	return;
}

template<typename T>
void quickSortBiDir(T arr[], int n) {
	__quickSortBD(arr, 0, n - 1);
	return;
}

template<typename T>
void __quickSort3Ways(T arr[], int left, int right) {
	if (left >= right)
		return;

	T v = arr[left];
	// [left+1, less] contain <v members, (less, i) contains = v, [big, right] >v
	int less = left, big = right + 1;
	for (int i = left + 1; i < big; i++) {
		if (arr[i] < v) {
			swap(arr[less + 1], arr[i]);
			less++;
		}
		else if (arr[i] > v) {
			swap(arr[big - 1], arr[i]);
			i--;
			big--;
		}
	}
	swap(arr[left], arr[less]);

	__quickSort3Ways(arr, left, less-1);
	__quickSort3Ways(arr, big, right);
	return;
}

template<typename T>
void quickSort3Ways(T arr[], int n) {
	__quickSort3Ways(arr, 0, n-1);
	return;
}