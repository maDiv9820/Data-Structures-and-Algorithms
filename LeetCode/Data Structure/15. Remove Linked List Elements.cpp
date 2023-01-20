/*
Remove Linked List Elements

Given the head of a linked list and an integer val, remove all the nodes of the linked list 
that has Node.val == val, and return the new head.

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

Constraints:

    The number of nodes in the list is in the range [0, 104].
    1 <= Node.val <= 50
    0 <= val <= 50
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *front = head, *tail = NULL;
    while(front) {
        if(front->val == val) {
            if(front == head) {
                head = head->next;
                front = head;
            }
            else {
                tail->next = front->next;
                front = front->next;
            }
        }
        else {
            tail = front;
            front = front->next;
        }
    }
    return head;
}

int main() {
    ListNode *head,*tail;
    head = tail = NULL;
    int n;
    cin >> n;
    while(n != -1) {
        if(head == NULL)
            head = tail = new ListNode(n);
        else {
            tail->next = new ListNode(n);
            tail = tail->next;
        }
        cin >> n;
    }
    cin >> n;
    head = removeElements(head,n);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}