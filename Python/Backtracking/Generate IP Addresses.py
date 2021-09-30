""" Given a string S containing only digits, Your task is to complete the function genIp() which 
returns a vector containing all possible combination of valid IPv4 ip address and takes only a 
string S as its only argument.

Note : Order doesn't matter.

For string 11211 the ip address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Input:
The first line of input will contain no of test cases T. Then T test cases follow . 
Each test case will contains a string S. 

Output:
For each test case, print the ip addresses in sorted order. You don't need to print it, 
printing is done by driver code.


Your Task:
Your task is just to complete the function genIp().

Expected Time Complexity: O(N * N * N * N)
Expected Auxiliary Space: O(N * N * N * N)

Constraints:
1<=T<=100
1<=N<=16
here, N = length of S.
S only contains digits(i.e. 0-9)

Example(To be used only for expected output):
Input
1
1111

Output

1.1.1.1 """