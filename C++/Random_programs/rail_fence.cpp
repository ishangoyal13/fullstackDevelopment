#include<bits/stdc++.h>
using namespace std;

/*===== TREENODE CODE =====
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode * left, TreeNode * right): val(x), left(left), right(right) {}
};
*/

/* == GRAPH NODE TEMPLATE CODE ===
struct Node {
    int val;
    vector < Node * > neighbors;
    Node(): val(0), neighbors({}) {};
    Node(int x): val(x), neighbors({}) {};
    Node(int x, vector < Node * > neighbors): val(x), neighbors(neighbors) {};
};
*/
string rail_fence(string str,int depth)
{
	int  n = str.length();
	if(depth >= n) return str;
	string ans;
	int j = 0,i=0;
	while(j<n){
		ans+=str[i];
		i += depth;
		i%=n;
		j++;
	}
	return ans;
}

int main(){
   	cout << rail_fence("all the best for exams",2) << endl;
	return 0;
}
