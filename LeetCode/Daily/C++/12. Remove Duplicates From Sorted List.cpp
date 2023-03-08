/*
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
ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *cur = head, *forw = NULL;
    map<int,int> m;
    while(cur) {
        m[cur->val]++;
        cur = cur->next;
    }
    for(map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
        if(it->second == 1) {
            if(!cur)
                cur = forw = new ListNode(it->first);
            else {
                forw->next = new ListNode(it->first);
                forw = forw->next;
            }
        }
    }
    return cur;
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
    head = deleteDuplicates(head);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}