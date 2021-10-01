# Using pointers

def isSubsequence(s, t):
    
    if s == '':
        return True
    
    ptr1 = 0
    ptr2 = 0
    length1 = len(s)
    length2 = len(t)
    
    while ptr2 < length2 and ptr1 < length1:
        if s[ptr1] == t[ptr2]:
            ptr1 += 1
            ptr2 += 1
        else:
            ptr2 += 1
            
    return ptr1 == length1

# Time Complexity : O(n)
# Space Complexity : O(1)