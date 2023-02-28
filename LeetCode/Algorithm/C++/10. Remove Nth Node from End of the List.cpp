/*
Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
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

ListNode* reverse(ListNode* head) {
    ListNode *front = head, *tail = NULL;
    while(front) {
        ListNode* nxt = front->next;
        front->next = tail;
        tail = front;
        front = nxt;
    }
    return tail;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    head = reverse(head);
    int count = 1;
    ListNode *front = head, *tail = NULL;
    while(front != NULL) {
        if(count == n) {
            if(tail == NULL)
                head = head->next;
            else
                tail->next = front->next;
            break;
        }
        tail = front;
        front = front->next;
        count++;
    }
    head = reverse(head);
    return head;
}

int main() {
    ListNode *head, *tail;
    head = tail = NULL;
    int n;
    cin >> n;
    while(n != 0) {
        if(head == NULL)
            head = tail = new ListNode(n);
        else {
            tail->next = new ListNode(n);
            tail = tail->next;
        }
        cin >> n;
    }
    cin >> n;
    ListNode* newNode = removeNthFromEnd(head,n);
    while(newNode) {
        cout << newNode->val << " ";
        newNode = newNode->next;
    }
    cout << endl;
}