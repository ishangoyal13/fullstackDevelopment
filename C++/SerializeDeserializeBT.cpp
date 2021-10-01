/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL){
            return "X";
        }
        
        string leftTree = serialize(root->left);
        string rightTree = serialize(root->right);
        
        return std::to_string(root->val) + ',' + leftTree + ',' + rightTree;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        
        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            q.push(substr);
        }
        
        TreeNode* root = deserializeHelper(q);
        
        return root;
        
        
        
    }
    
    TreeNode* deserializeHelper(queue<string> &q){
        if(q.size() == 0){
            return NULL;
        }
        
        string top = q.front();
        q.pop();
                
        
        if(top == "X"){
            return NULL;
        }
        
        
        
        TreeNode* newNode = new TreeNode(std::stoi( top ));
        newNode->left = deserializeHelper(q);
        newNode->right = deserializeHelper(q);
        
        return newNode;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));