#pragma once

#include <cassert>

using namespace std;

namespace UF2 {

	class UnionFind {
	private:
		int count;
		int* parent;

		UnionFind(int count) {
			this->count = count;
			parent = new int[count];

			for (int i = 0; i < count; i++) {
				parent[i] = i;
			}
		}

		~UnionFind() {
			delete parent;
		}

		int find(int p) {
			assert(p >= 0 && p < count);
			
			while (p != parent[p]) {
				p = parent[p];
			}
			return p;
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		void unionElement(int p, int q) {
			int pId = find(p);
			int qId = find(q);

			if (pId == qId)
				return;

			parent[pId] = qId;
		}

	};


}

