#include <vector>
#include <algorithm>
#include "EggDropping.h"

using namespace std;
/*
Objec­tive:  There are n number of eggs and building which has k floors. 
Write an algorithm to find the minimum number of drops is required to
know the floor from which if egg is dropped, it will break.

Note:

One trial is – dropping an egg once from the particular floor.
If egg does not break after dropping, will be used again.
If egg breaks when dropped from some floor then it will break if dropped from any higher floor.
If egg does not break when dropped from some floor then it will not break if dropped from any lower floor.
*/
int MinEggDroppingRc(int nEgg, int floor) {
	if (floor == 0)
		return 0;
	if (floor == 1)
		return 1;
	if (nEgg == 1)
		return floor;

	int ret = 0;
	for (int i = 1; i <= floor; i++) {
		ret = max(ret, 1 + min(MinEggDroppingRc(nEgg - 1, i-1), MinEggDroppingRc(nEgg, floor - i)));
	}
	return ret;
}

int MinEggDroppingDp(int nEgg, int floor) {
	vector<vector<int>> mem(nEgg + 1);

	for (int i = 0; i <= nEgg; i++) {
		mem[i].resize(floor + 1);
		mem[i][0] = 0;
	}
	for (int i = 0; i <= floor; i++) {
		mem[1][i] = i;
	}

	for (int i = 2; i <= nEgg; i++) {
		for (int j = 1; j <= floor; j++) {
			mem[i][j] = 0;
			for (int k = 1; k <= j; k++)
				mem[i][j] = max(mem[i][j],1 + min(mem[i - 1][k - 1], mem[i][j - k]));
		}
	}

	return mem[nEgg][floor];
}

