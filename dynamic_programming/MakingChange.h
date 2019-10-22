#pragma once
#include <vector>
#include <algorithm>

using namespace std;

/*
Making Change. You are given n types of coin denominations of values
v(1) < v(2) < ... < v(n) (all integers). Assume v(1) = 1, so you can 
always make change for any amount of money C. Give an algorithm which 
makes change for an amount of money C with as few coins as possible. 

source: https://people.cs.clemson.edu/~bcdean/dp_practice/
*/

int makeChange(const vector<int>& coins, int value) {

	vector<int> dp(value + 1); // dp[j] is minimum num of coins for change value=j
	int minNum;

	if (value == 0)
		return 0;

	for (int j = 1; j <= value; j++) {
		minNum = j + 1;
		for (int i = 0; i < coins.size(); i++) {
			if (j - coins[i] > 0) {
				if (dp[j - coins[i]] != -1 && dp[j - coins[i]] + 1 < minNum) {	// value = j-coins[i] can make change 
					minNum = dp[j - coins[i]] + 1;
				}
			}
			else if (j - coins[i] == 0) {
				minNum = 1;
			}
			else
				continue;
		}
		if (minNum == j + 1)
			minNum = -1;
		dp[j] = minNum;
	}
	return dp[value];
}

