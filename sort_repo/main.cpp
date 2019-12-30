#include <iostream>
#include "selectionSort.h"
#include "insertSort.h"
#include "mergeSort1.h"
#include "mergeSort2.h"
#include "quickSort.h"
#include "MinHeap.h"
#include "sortTestHelper.h"
#include "BubbleSort.h"
#include "ShellSort.h"

using namespace std;

int main() {
	int n = 1000;
	int *arr = generateRandomArray<int>(n, 0, 100);
	int* arr1 = copyArray<int>(arr, n);
	
	testSort(arr, n, "bubble Sort", bubbleSort);
	testSort(arr1, n, "shell Sort", shellSort);

	int* arr2 = genNearlyOrderedArr<int>(n, 4);
	int* arr3 = copyArray<int>(arr2, n);
	testSort(arr2, n, "merget Sort", mergeSortBU);
	testSort(arr3, n, "insert Sort", insertSort);

	delete[] arr;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}




