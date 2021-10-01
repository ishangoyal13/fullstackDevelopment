/*
Given a String S, Find all possible Palindromic partitions of the given String.

Input:
S = "madam"
Output:
m a d a m
m ada m
madam

code by iamkakashi
*/
    #include<bits/stdc++.h>
    using namespace std;
    
    bool found(string s){
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void solve(string s,vector<vector<string>>&v1,vector<string>&v){
        int n=s.length();
        if(n==0){
            v1.push_back(v);
            return;
        }
        for(int i=1;i<=n;i++){
            if(found(s.substr(0,i))){
                v.push_back(s.substr(0,i));
                solve(s.substr(i,n-i),v1,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>>v1;
        vector<string>v;
        int len=s.length();
        solve(s,v1,v);
        return v1;
    }
    int main(){
        string s;
        cin>>s;
        vector<vector<string>>v=allPalindromicPerms(s);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }