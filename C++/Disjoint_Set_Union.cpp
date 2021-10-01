// Disjoint Set Union is a powerful tool which has many applications in graph problems
// eg: finding cycles in undirected graphs


#include<bits/stdc++.h>
using namespace std;
struct DSU {
	vector<int>rank;
	vector<int>parent;
	DSU(int n) {
		rank.resize(n);
		fill(rank.begin(), rank.end(), 1);
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	// this is the find / get function
	// it finds the parent of given node
	// this method is using compression by rank for optimisation
	int get(int a) {
		int Parent_of_a = parent[a];
		if (Parent_of_a == a)
			return a;
		return parent[a] = get(parent[Parent_of_a]);
	}

	// this is the union/merge function
	// merges two nodes based upon the ranks
	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b)
			return;
		if (rank[a] > rank[b])
			parent[b] = a;
		else if (rank[b] > rank[a])
			parent[a] = b;
		else {
			parent[a] = b;
			rank[b] += 1;
		}
	}
};
int main() {
	// number of nodes
	int n;
	cin >> n;
	// initializing our DSU
	DSU u1 = DSU(n);

	// number of edges
	int edges;
	cin >> edges;

	// merge the given edges
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		u1.merge(u, v);
	}
	return 0;
}