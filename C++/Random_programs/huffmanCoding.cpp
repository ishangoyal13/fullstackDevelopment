

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int freq;
    char ch;
    Node *left;
    Node *right;
};
// to create new node ;
Node *getNode(char ch,int freq,Node *left,Node *right){
    
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node *root,string str,unordered_map<char, string> &huffmanCode){
    if(root == nullptr){
        return;
    }   

    // found a leaf node
    if(!root->left && !root->right){
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}


void huffmanCode(string s,int n){


    // step  1 - count frequency of each chareacterrs... 

    unordered_map<char,int> freq;
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }

    // create a node for each char and store it in priority_queue..
    priority_queue<Node *,vector<Node*>,comp> pq;
    for(auto i:freq){
        pq.push(getNode(i.first,i.second,nullptr,nullptr));
    }

    // do untill there is only one node in priority_queue;
    while(pq.size()!=1){
        // remove two nodes of highest priority i.e of lowest freq;
        Node *left = pq.top(); 
        pq.pop();
		Node *right = pq.top();
        pq.pop();
        // Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
        int sm = left->freq+right->freq;
        pq.push(getNode('\0',sm,left,right));  
    }

    // root stores pointer to root node of huffman tree..
    Node *root = pq.top();
    // traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
    unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);
    cout << "Huffman Codes are :\n" << '\n';
	for (auto it: huffmanCode) {
		cout << it.first << " " << it.second << '\n';
	}

    cout << "\nOriginal string was :\n" << s << '\n';

	// print encoded string
	string str = "";
	for (char ch: s) {
		str += huffmanCode[ch];
	}

    /// DECODING OF MSG now 
    cout << "\nEncoded string is :\n" << str << '\n';

	// traverse the Huffman Tree again and this time
	// decode the encoded string
	int index = -1;
	cout << "\nDecoded string is: \n";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}

}
int main(){
    string s;
    cin>>s;
    int n = s.length();
    huffmanCode(s,n);
}
