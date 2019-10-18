#include <iostream>
#include "selectionSort.h"
#include "sortTestHelper.h"

using namespace std;

int main() {
	int n = 100000;
	int *arr = generateRandomArray<int>(n, 0, 100);
	testSort(arr, n, "selection Sort", selectionSort);

	int* arr2 = genNearlyOrderedArr<int>(n, 4);
	testSort(arr2, n, "selection Sort", selectionSort);

	delete arr;
	delete arr2;

	return 0;
}




