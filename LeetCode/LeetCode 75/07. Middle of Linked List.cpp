/*
Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100
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

int length(ListNode* head) {
    int len = 0;
    while(head) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* middleNode(ListNode* head) {
    /*
        Solution:- Using Two Pointer Approach
        Time Complexity:- O(n)
        Space Complexity:- O(1)
        where n is the length of the list 
    */
    if(head == NULL || head->next == NULL)
        return head;
    ListNode *slow, *fast;
    slow = fast = head;
    while(fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(length(head) % 2 == 0)
        slow = slow->next;
    return slow;
}

int main() {
    ListNode *head, *tail;
    head = tail = NULL;
    int n;
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
    ListNode* middle = middleNode(head);
    while(middle) {
        cout << middle->val << " ";
        middle = middle->next;
    }
    cout << endl;
}