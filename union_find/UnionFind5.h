#pragma once

#include <cassert>

using namespace std;

namespace UF5 {

	class UnionFind {
	private:
		int count;
		int* parent;
		int* rank; // 以i为根节点的集合层数

		UnionFind(int count) {
			this->count = count;
			parent = new int[count];
			rank = new int[count];

			for (int i = 0; i < count; i++) {
				parent[i] = i;
				rank[i] = i;
			}
		}

		~UnionFind() {
			delete parent;
			delete rank;
		}

		int find(int p) {
			assert(p >= 0 && p < count);

			/*while (p != parent[p]) {
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			 return p;
			*/
			if (p != parent[p])
				parent[p] = find(parent[p]);

			return parent[p];
		}

		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		void unionElement(int p, int q) {
			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
				return;

			if (rank[pRoot] < rank[qRoot]) {
				parent[pRoot] = parent[qRoot];
			}
			else if (rank[qRoot] < rank[pRoot]) {
				parent[qRoot] = parent[pRoot];
			}
			else {
				parent[qRoot] = parent[pRoot];
				rank[pRoot] += 1;
			}
			return;
		}

	};


}

