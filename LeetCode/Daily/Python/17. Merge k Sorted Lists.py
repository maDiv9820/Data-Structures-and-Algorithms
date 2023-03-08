'''
Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it. 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []


Constraints:

    k == lists.length
    0 <= k <= 104
    0 <= lists[i].length <= 500
    -104 <= lists[i][j] <= 104
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 104.
'''
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def mergeKLists(self, lists: list[list[ListNode]]) -> ListNode:
        head = None; tail = None; values = []
        for ptr in lists:
            while ptr:
                values.append(ptr.val)
                ptr = ptr.next
        values.sort()
        for x in values:
            if not head:
                head = tail = ListNode(x)
            else:
                tail.next = ListNode(x)
                tail = tail.next
        return head

n = int(input())
lists = []
for index in range(n):
    head = None; tail = None
    values = [int(x) for x in input().split()]
    for x in values:
        if not head:
            head = tail = ListNode(x)
        else:
            tail.next = ListNode(x)
            tail = tail.next
    lists.append(head)
sol = Solution()
head = sol.mergeKLists(lists)
while head:
    print(head.val, end = ' ')
    head = head.next
print()
