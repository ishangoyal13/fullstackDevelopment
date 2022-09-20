
#include <bits/stdc++.h>
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

void print_horizontal_line(int n){for(int i=0; i<n; i++)cout << "--"; cout << endl;}
string row_transposition_technique(string text, vector<int> nums, bool print = false, string seperator = " | ")
{
    vector<vector<char>> helper;
    int j = 0, row_size = nums.size();
    vector<char> curr_row;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (i && i % row_size == 0)
        {
            helper.push_back(curr_row);
            curr_row.resize(0);
        }
        curr_row.push_back(text[i]);
    }
   
    if(curr_row.size()) helper.push_back(curr_row);
  if(print)  print_horizontal_line(2*row_size);
    if(print) for(auto a : nums) cout << a << seperator;
    if(print) cout << "\n";
   if(print)  print_horizontal_line(row_size * 2);
    if(print) for (auto aa : helper) {
        for (auto a : aa)
            cout << a << seperator;
        cout << endl;
    }
    map<int,int> m;
    for (size_t i = 0; i < row_size; i++)
        m[nums[i]] = i;
    string cypher = "";
    int col_size = helper.size();
    for(auto val : m) {
        int j = val.second;
        for(int i = 0; i < col_size; i++) cypher += (helper[i][j]);
    }
    if (print)cout << endl;
    return cypher;
}

int main()
{
    vector<int> nums = {2, 3, 1, 4, 5, 7};
    string cypher = row_transposition_technique("sachin duhan is dancing IN DTU", nums);
    cout << "[RESULT] - '" << cypher << "'" << endl;
    return 0;
}