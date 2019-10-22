#include <iostream>
#include <vector>
#include <ctime>
#include <utility>
#include "MaxValueContiguousSubseq.h"

using namespace std;

int main() {
	int n = 10;
	vector<int> arr(n);

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = (rand() % 20) + (-10);
	}

	pair<vector<int>, int> ret = maxValueConSubseq(arr, n);
	int start = ret.first[0];
	int end = ret.first[1];
	int maxValue = ret.second;

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	cout << "subsequence at [" << start << ", " << end << "]" << endl;
	cout << "max value = " << maxValue << endl;
	return 0;
}




