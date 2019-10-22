#pragma once
#include <utility>
#include <vector>
#include <cassert>

using namespace std;

/*
Maximum Value Contiguous Subsequence. Given a sequence of n 
real numbers A(1) ... A(n), determine a contiguous subsequence
A(i) ... A(j) for which the sum of elements in the subsequence
is maximized.

source: https://people.cs.clemson.edu/~bcdean/dp_practice/
*/

template<typename Value>
pair<vector<int>, Value> maxValueConSubseq(const vector<Value> &arr, int n) {
	assert(n != 0);

	pair<vector<int>, Value> ret;

	vector<Value> dp(n);	/*dp[i] is the max sum over all window ending at index i*/
	vector<int> index(n);	/*index[i] is the starting index of the window ending at index i*/
	dp[0] = arr[0], index[0] = 0;
	for (int i = 1; i < n; i++) { 
		bool added = (arr[i] + dp[i - 1]) >= arr[i];
		if (added) {
			dp[i] = arr[i] + dp[i - 1];
			index[i] = index[i - 1];
		}
		else {
			dp[i] = arr[i];
			index[i] = i;
		}
	}

	Value maxValue = dp[0];
	int maxIndex = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > maxValue) {
			maxValue = dp[i];
			maxIndex = i;
		}
	}
	ret.first.push_back(index[maxIndex]);
	ret.first.push_back(maxIndex);
	ret.second = maxValue;
	return ret;
}




