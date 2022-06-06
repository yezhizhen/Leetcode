# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    @staticmethod
    def advance(head:ListNode, steps: int = 1) -> Optional[ListNode]:
        for i in range(steps):
            head = head.next
        return head
    
    @staticmethod 
    def find_length(head:ListNode) -> int:
        res = 0
        while head:
            head = Solution.advance(head)
            res += 1
        return res
        
        
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        lenA = Solution.find_length(headA)
        lenB = Solution.find_length(headB)
        
        if lenA > lenB:
            headA = Solution.advance(headA, lenA - lenB)
        elif lenB > lenA:
            headB = Solution.advance(headB, lenB - lenA)
        
        while headA and headA != headB:
            headA = Solution.advance(headA)
            headB = Solution.advance(headB)
        
        return headA
        