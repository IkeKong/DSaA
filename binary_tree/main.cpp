#include <iostream>
#include "sortTestHelper.h"
#include "quickSort.h"

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
	int left = 0, right = n - 1;

	while (left <= right) {
		int mid = (right - left) / 2 + left;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

template<typename T>
int __binarySearchRecurrent(T arr[], int left, int right, T target) {
	if (right < left)
		return -1;
	int mid = left + (right - left) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return __binarySearchRecurrent(arr, left, mid - 1, target);
	else
		return __binarySearchRecurrent(arr, mid + 1, right, target);
}

template<typename T>
int binarySearchRecur(T arr[], int n, T target) {
	return __binarySearchRecurrent(arr, 0, n - 1, target);
}

template<typename T>
int floor(T arr[], int n, T target) {
	int left = 0, right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (arr[mid] > target && mid - 1 > 0)
		return mid - 1;
	else
		return mid;
}

template<typename T>
int ceil(T arr[], int n, T target) {
	int left = 0, right = n - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (arr[mid] < target && mid + 1 < n)
		return mid + 1;
	else
		return mid;
}


int main() {
	int n = 50;
	int* arr = generateRandomArray<int>(n, 0, 100);
	printArray(arr, n);
	quickSort3Ways(arr, n);
	printArray(arr, n);

	int index = binarySearch(arr, n, 10);
	cout << "target in array: " << index << endl;
	int index1 = binarySearchRecur(arr, n, 10);
	cout << "target in array: " << index1 << endl;

	int index2 = floor(arr, n, 10);
	cout << "target in array: " << index2 << endl;

	int index3 = ceil(arr, n, 10);
	cout << "target in array: " << index3 << endl;
	return 0;
}

