#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template<typename T>
class MinHeap
{
private:
	T* heap;
	int _capacity;
	int size;

	void __shiftDown(int i) {
		while (2 * i <= size) {
			int j = 2 * i;
			if (j + 1 <= size && heap[j + 1] < heap[j]) {
				j += 1;
			}
			if (heap[i] <= heap[j])
				break;
			swap(heap[i], heap[j]);
			i = j;
		}
		return;
	}

	void __shiftUp(int i) {
		while (i > 1 && heap[i] < heap[i / 2]) {
			swap(heap[i], heap[i / 2]);
			i /= 2;
		}
		return;
	}

public:
	MinHeap(T arr[], int n) {
		heap = new T[n+1];
		for (int i = 1; i <= n; i++) {
			heap[i] = arr[i-1];
		}
		_capacity = n;
		size = n;

		for (int i = n / 2; i >= 1; i--)
			__shiftDown(i);

	}

	~MinHeap() {
		delete[] heap;
	}

	int count() {
		return size;
	}

	int capacity() {
		return _capacity;
	}

	T top() {
		assert(size > 0);
		return heap[1];
	}

	void pop() {
		assert(size > 0);

		heap[1] = heap[size];
		size--;
		__shiftDown(1);
		return;
	}

	void insert(T e) {
		assert(size < capacity);
		heap[size + 1] = e;
		size++;
		__shiftUp(size + 1);
		return;
	}

};

template<typename T>
void heapSort(T arr[], int n) {
	MinHeap<T> data(arr, n);
	for (int i = 0; i < n; i++) {
		arr[i] = data.top();
		data.pop();  
	}
	return;

}
