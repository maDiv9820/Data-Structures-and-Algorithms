'''
Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list. Return the linked list sorted as well. 

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
'''
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        m = {}; cur = head; prev = None
        while cur:
            m[cur.val] = m.get(cur.val,0)+1
            cur = cur.next
        for val,freq in m.items():
            if freq == 1:
                if cur is None:
                    cur = prev = ListNode(val)
                else:
                    prev.next = ListNode(val)
                    prev = prev.next
        return cur
head = None; prev = None
inputs = [int(x) for x in input().split()]
for x in inputs:
    if head is None:
        head = prev = ListNode(x)
    else:
        prev.next = ListNode(x)
        prev = prev.next
sol = Solution()
cur = sol.deleteDuplicates(head)
while cur:
    print(cur.val, end = ' ')
    cur = cur.next
print()