#pragma once

#include<iostream>
#include "sortTestHelper.h"
using namespace std;

template<typename T>
void merge(T arr[], int left_idx, int mid, int right_idx) {
	int left_n = mid - left_idx + 1, right_n = right_idx - mid;

	T* left_arr = new T[left_n];
	T* right_arr = new T[right_n];

	for (int i = 0; i < left_n; i++) {
		left_arr[i] = arr[left_idx + i];
	}
	for (int i = 0; i < right_n; i++) {
		right_arr[i] = arr[mid+1+i];
	}

	int n = right_idx - left_idx + 1;
	int j = 0, k = 0;
	for (int i = 0; i < n; i++) {
		if (j >= left_n)
			arr[left_idx + i] = right_arr[k++];
		else if (k >= right_n)
			arr[left_idx + i] = left_arr[j++];
		else if (left_arr[j] < right_arr[k])
			arr[left_idx + i] = left_arr[j++];
		else
			arr[left_idx + i] = right_arr[k++];
	}
	delete[] left_arr;
	delete[] right_arr;
	return;
}

template<typename T>
void __Sort(T arr[], int left_idx, int right_idx) {
	int mid = (left_idx + right_idx) / 2;
	if (left_idx >= right_idx)
		return;

	__Sort(arr, left_idx, mid);
	__Sort(arr, mid + 1, right_idx);
	merge(arr, left_idx, mid, right_idx);
	return;
}

template<typename T>
void mergeSortUD(T arr[], int n) {
	__Sort(arr, 0, n - 1);
}
