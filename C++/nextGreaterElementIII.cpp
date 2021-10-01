#include<string.h>
class Solution {
public:
    int nextGreaterElement(int n) {
        string k = to_string(n);
        bool val = next_permutation(k.begin(),k.end());
        if(val == false){
            return -1;
        }
        else{
            long n1 = stol(k);
            if(n1>INT_MAX){
                return -1;
            }
            
            return n1;    
        }
        
    }
};