#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Given a number N, write an algorithm to convert 
that number to 1. Below are the allowed operations.
If N is even, do N = N/2.
If N is odd, either do N =N ¨C 1 or do N = N + 1
*/

int MinOpConvertNum(int num) {
	if (num == 1)
		return 0;
	if (num % 2 == 0) {
		return 1 + MinOpConvertNum(num / 2);
	}
	else { // num is odd , note: num + 1 may be out of range exception
		return min(MinOpConvertNum((num - 1) / 2 + 1) + 2, MinOpConvertNum(num - 1) + 1);
	}
}

int MinOpConvertNumDp(int num) {
	vector<int> mem(num + 1);
	mem[0] = 0, mem[1] = 0, mem[2] = 1;
	if (num < 3) return mem[num];
	for (int i = 3; i <= num; i++) {
		if (i % 2 == 0)
			mem[i] = 1 + mem[i / 2];
		else
			mem[i] = min(mem[(i - 1) / 2 + 1] + 2, mem[i - 1] + 1);
	}
	return mem[num];
}


