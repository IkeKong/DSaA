#include <iostream>
#include <vector>
#include <ctime>
#include <utility>
#include "MaxValueContiguousSubseq.h"
#include "MinOpConvertNum.h"
#include "EggDropping.h"

using namespace std;

int main() {
	int n1 = 16, n2 = 11;
	int ret1 = MinOpConvertNumDp(n1);
	int ret2 = MinOpConvertNumDp(n2);
	cout << "minimum num of ops required to convert " << n1 <<" to 1 is " << ret1 << endl;
	cout << "minimum num of ops required to convert " << n2 << " to 1 is " << ret2 << endl;

	int eggs = MinEggDroppingRc(2, 100);
	cout << "with eggs=2, floor=10, " << " need " << eggs << " times trials." << endl;
	/*vector<int> arr(n);

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
	cout << "max value = " << maxValue << endl;*/
	return 0;
}




