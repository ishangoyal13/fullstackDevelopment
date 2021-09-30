// For finding Kth ancestor of a node using Binary Lifting when queries are given


// Note: this code is written for nodes having values 1...n

#include<bits/stdc++.h>
using namespace std;

// creating our Lift Matrix
vector < vector<int>>lift;

/// adding lifted parents
void Binary_Lift(vector<int>&parent, int n) {
	lift.resize(20, vector<int>(parent.size(), -1));

	// marking the first parent of every node
	for (int i = 2; i <= n; i++) {
		lift[0][i] = parent[i];
	}

	// marking parents
	for (int i = 1; i < 20; i++) {
		for (int node = 1; node <= n; node++) {
			int parentOfcurrentNode = lift[i - 1][node];
			// this means the parent exists and its not the root node
			if (parentOfcurrentNode != -1) {
				lift[i][node] = lift[i - 1][parentOfcurrentNode];
			}
		}
	}
}

// for query
int Query(int node, int Kthancestory) {

	for (int i = 0; i < 20; i++) {
		// checking if the current node is set or not
		if (Kthancestory & (1 << i)) {
			node = lift[i][node];

			// if this is the top most node return
			if (node == -1) {
				return -1;
			}
		}
	}
	// finally returning the kthancestory
	return node;
}
int main() {
	int nodes, queries;
	cin >> nodes >> queries;
	vector<int>parent(nodes + 1, 0);

	// Note: nodes are 1...n
	for (int i = 2; i <= nodes; i++) {
		int val;
		cin >> val;
		parent[i] = val;
	}

	Binary_Lift(parent, nodes);
	while (queries--) {
		int node, ancestor;
		cin >> node >> ancestor;
		int ans = Query(node, ancestor);
		cout << ans << endl;
	}
}