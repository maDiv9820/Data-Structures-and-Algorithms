/*
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
*/
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
pair<ListNode*,ListNode*> reverseLL(ListNode* head) {
    ListNode *cur = head, *prev = nullptr, *forw = nullptr;
    while(cur) {
        forw = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forw;
    }
    return {prev,head};
}
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || !head->next || left >= right)
        return head;
    ListNode *c1 = head, *p1 = nullptr, *c2 = head, *p2 = nullptr, *temp = nullptr;
    while(c1 && left > 1) {
        p1 = c1;
        c1 = c1->next;
        left--;
    }
    while(c2 && right > 1) {
        p2 = c2;
        c2 = c2->next;
        right--;
    }
    if(p1)
        p1->next = nullptr;
    temp = c2->next;
    c2->next = nullptr;
    pair<ListNode*,ListNode*> p = reverseLL(c1);
    if(p1)
        p1->next = p.first;
    else
        head = p.first;
    p.second->next = temp;
    return head;
}
int main() {
    int n,left,right;
    cin >> n;
    vector<int> v(n,0);
    for(int index = 0; index < n; index++)
        cin >> v[index];
    ListNode *head = nullptr, *tail = nullptr;
    for(int index = 0; index < n; index++) {
        if(!head)
            head = tail = new ListNode(v[index]);
        else {
            tail->next = new ListNode(v[index]);
            tail = tail->next;
        }
    }
    cin >> left >> right;
    head = reverseBetween(head,left,right);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}