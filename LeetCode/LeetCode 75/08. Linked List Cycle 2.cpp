/*
Linked List Cycle II

Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list 
that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list. 

Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head) {
    /*
        Solution 1:- Using hashmaps
        Time Complexity:- O(n)
        Space Complexity:- O(n)
    
    map<ListNode*, ListNode*> m;
    while(head) {
        if(m.count(head->next) == 1)
            return head->next;
        m[head] = head->next;
        head = head->next;
    }
    return NULL;
    */
    /*
        Solution 2:- Using Two Approach
        Time Complexity:- O(n)
        Space Complexity:- O(1)
    */
    if(head == NULL || head->next == NULL)
        return NULL;
    ListNode *slow, *fast;
    slow = fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast && fast->next) {
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow != fast)
        return NULL;
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    ListNode *head, *tail;
    int n;
    head = tail = NULL;
    cin >> n;
    while(n != 0) {
        if(head == NULL) {
            head = tail = new ListNode(n);
        }
        else {
            tail->next = new ListNode(n);
            tail = tail->next;
        }
        cin >> n;
    }
    tail->next = head->next->next;
    ListNode* cycle = detectCycle(head);
    if(cycle) {
        int pos = 0;
        while(head) {
            if(head == cycle)
                break;
            pos++;
            head = head->next;
        }
        cout << cycle->val << endl;
        cout << pos << endl;
    }
    else
        cout << -1 << endl;
}