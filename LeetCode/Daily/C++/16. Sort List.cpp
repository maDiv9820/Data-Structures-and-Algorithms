/*
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
ListNode* merge(ListNode* h1, ListNode* h2) {
    if(!h1)
        return h2;
    if(!h2)
        return h1;
    ListNode *Cur = nullptr, *Forw = nullptr;
    if(h1->val <= h2->val) {
        Cur = Forw = h1;
        h1 = h1->next;
    }
    else {
        Cur = Forw = h2;
        h2 = h2->next;
    }
    while(h1 && h2) {
        if(h1->val <= h2->val) {
            Forw->next = h1;
            Forw = Forw->next;
            h1 = h1->next;
        }
        else {
            Forw->next = h2;
            Forw = Forw->next;
            h2 = h2->next;
        }   
    }
    while(h1) {
        Forw->next = h1;
        Forw = Forw->next;
        h1 = h1->next;
    }
    while(h2) {
        Forw->next = h2;
        Forw = Forw->next;
        h2 = h2->next;
    }
    return Cur;
}
ListNode* sortList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode* slow = head, *fast = head->next;
    while(fast && fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *h2 = slow->next;
    slow->next = NULL;
    ListNode *h1 = sortList(head);
    h2 = sortList(h2);
    head = merge(h1,h2);
    return head;
}
int main() {
    int n;
    cin >> n;
    vector<int> values(n,0);
    for(int index = 0; index < n; index++)
        cin >> values[index];
    ListNode *head = NULL, *cur = NULL;
    for(int index = 0; index < n; index++) {
        if(head == NULL)
            head = cur = new ListNode(values[index]);
        else {
            cur->next = new ListNode(values[index]);
            cur = cur->next;
        }
    }
    head = sortList(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}