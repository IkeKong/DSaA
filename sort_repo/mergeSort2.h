#pragma once
#include <algorithm>
#include "mergeSort1.h"
using namespace std;

template<typename T>
void mergeSortBU(T arr[], int n) {
	for (int sz = 1; sz <= n; sz += sz) {
		for (int i = 0; i + sz < n; i += sz + sz) {
			merge(arr, i, i + sz - 1, min(i + 2 * sz - 1, n-1));
		}
	}
	return;
}

