# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
# An input string is valid if:
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.


def balanced(exp,s):
    for i in exp:
        if i in ('(','{','['):
            s.append(i)
        else:
            if len(s)==0:
                break
            char=s.pop()
            if i==')':
                if char!='(':
                    break
            if i=='}':
                if char!='{':
                    break
            if i==']':
                if char!='[':
                    break
    if len(s)==0:
        print("balenced")
    else:
        print("UnBalenced")

if __name__ == "__main__":
    s=[]
    exp="({[]})"
    balanced(exp,s)
