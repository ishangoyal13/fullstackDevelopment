/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* Input: n = 3
* Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<string> &res,string curr,int open,int close,int max) {
  if(curr.length()==max*2) { 
    res.push_back(curr);
    return;
  }
  else {
    if(open<max)
      backtrack(res,curr+"(",open+1,close,max);
    if(close<open)
      backtrack(res,curr+")",open,close+1,max);
            
  }      
}

vector<string> generateParenthesis(int n) {
  vector<string> res;
  backtrack(res,"",0,0,n);
  return res;
}

int main() {
	int n = 3;
	vector<string> parenthesis = generateParenthesis(n);
  for(auto str : parenthesis) {
    cout << str << " ";
  }
	return 0;
}
