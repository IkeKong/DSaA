#pragma once

#include <cassert>

using namespace std;

namespace UF1 {
	class UnionFind {
	private:
		int* id;
		int count;

		UnionFind(int count) {
			this->count = count;
			id = new int[count];
			
			for (int i = 0; i < count; i++) {
				id[i] = i;
			}
		}

		~UnionFind() {
			delete[]id;
		}

	public:
		int find(int p) {
			assert(p >= 0 && p < count);
			return id[p];
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		void unionElement(int p, int q) {		// O(n)
			int pId = find(p);
			int qId = find(q);

			if (pId == qId)
				return;

			for (int i = 0; i < count; i++) {
				if (id[i] == pId)
					id[i] = qId;
			}
			return;
		}

	};

}




