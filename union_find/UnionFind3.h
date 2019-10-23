#pragma once

#include <cassert>

using namespace std;

namespace UF3 {

	class UnionFind {
	private:
		int count;
		int* parent;
		int* sz; // 以i为根节点的集合大小
		UnionFind(int count) {
			this->count = count;
			parent = new int[count];
			sz = new int[count];

			for (int i = 0; i < count; i++) {
				parent[i] = i;
				sz[i] = i;
			}
		}

		~UnionFind() {
			delete parent;
			delete sz;
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
			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
				return;

			if (sz[pRoot] < sz[qRoot]) {
				parent[pRoot] = parent[qRoot];
				sz[qRoot] += sz[pRoot];
			}
			else{
				parent[qRoot] = parent[pRoot];
				sz[pRoot] += sz[qRoot];
			}
			return;
		}

	};


}

