'''
Sort List

Given the head of a linked list, return the list after sorting it in ascending order. 

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

Constraints:

    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105
'''
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def __merge(self, head1: ListNode, head2: ListNode) -> ListNode:
        if not head1:
            return head2
        if not head2:
            return head1
        cur = None; next = None
        if head1.val <= head2.val:
            cur = next = head1
            head1 = head1.next
        else:
            cur = next = head2
            head2 = head2.next
        while head1 and head2:
            if head1.val <= head2.val:
                next.next = head1
                next = head1
                head1 = head1.next
            else:
                next.next = head2
                next = head2
                head2 = head2.next
        while head1:
            next.next = head1
            next = head1
            head1 = head1.next
        while head2:
            next.next = head2
            next = head2
            head2 = head2.next
        return cur 
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        middleNode = None; slow = head; fast = head.next
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        head1 = head
        head2 = slow.next
        slow.next = None
        head1 = self.sortList(head1)
        head2 = self.sortList(head2)
        head = self.__merge(head1,head2)
        return head

head = None; prev = None
inputs = [int(x) for x in input().split()]
for x in inputs:
    if head is None:
        head = prev = ListNode(x)
    else:
        prev.next = ListNode(x)
        prev = prev.next
sol = Solution()
cur = sol.sortList(head)
while cur:
    print(cur.val, end = ' ')
    cur = cur.next
print()