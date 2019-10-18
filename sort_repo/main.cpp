#include <iostream>
#include "selectionSort.h"
#include "insertSort.h"
#include "sortTestHelper.h"

using namespace std;

int main() {
	int n = 10000;
	int *arr = generateRandomArray<int>(n, 0, 100);
	int* arr1 = copyArray<int>(arr, n);
	testSort(arr, n, "selection Sort", selectionSort);
	testSort(arr1, n, "insert Sort", insertSort);

	int* arr2 = genNearlyOrderedArr<int>(n, 4);
	int* arr3 = copyArray<int>(arr, n);
	testSort(arr2, n, "selection Sort", selectionSort);
	testSort(arr3, n, "insert Sort", insertSort);

	delete arr;
	delete arr1;
	delete arr2;
	delete arr3;

	return 0;
}




