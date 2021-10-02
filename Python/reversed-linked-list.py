# TO reverse a linked list



class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        newhead= ListNode()
        def linkofthelink(orig,rev):
            stack=[]
            temp=orig
            while temp:
                stack.append(temp)
                temp=temp.next
            
            temp=stack.pop()
            rev=temp
            
            while stack:
                i=stack.pop()  
                temp.next=i    
                temp= temp.next
            
            temp.next = None     
            return rev

        if head:
            newhead = linkofthelink(head,newhead)
            return newhead
        else: 
            return None

