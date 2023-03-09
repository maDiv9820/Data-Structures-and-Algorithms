'''
Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:

    The number of nodes in the list is n.
    1 <= n <= 500
    -500 <= Node.val <= 500
    1 <= left <= right <= n
'''
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next
class Solution:
    def __reverseLL(self, head: ListNode) -> ListNode:
        cur = head; prev = None; forw = None;
        while cur:
            forw = cur.next
            cur.next = prev
            prev = cur
            cur = forw
        return prev,head
    
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if not head or not head.next or left >= right:
            return head
        c1 = head; p1 = None; c2 = head; p2 = None
        while c1 and left > 1:
            p1 = c1
            c1 = c1.next
            left -= 1
        while c2 and right > 1:
            p2 = c2
            c2 = c2.next
            right -= 1
        if p1:
            p1.next = None
        temp = c2.next
        c2.next = None
        pair = self.__reverseLL(c1)
        if p1:
            p1.next = pair[0]
        else:
            head = pair[0]
        pair[1].next = temp
        return head

head,tail = None,None
inputs = [int(x) for x in input().split()]
for x in inputs:
    if not head:
        head = tail = ListNode(x)
    else:
        tail.next = ListNode(x)
        tail = tail.next
left,right = map(int,input().split())
sol = Solution()
head = sol.reverseBetween(head,left,right)
while head:
    print(head.val, end = ' ')
    head = head.next
print()