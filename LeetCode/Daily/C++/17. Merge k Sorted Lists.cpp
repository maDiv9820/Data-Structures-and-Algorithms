/*
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
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> v;
    for(auto head: lists) {
        while(head) {
            v.emplace_back(head->val);
            head = head->next;
        }
    }
    sort(v.begin(),v.end());
    ListNode *head = nullptr, *tail = nullptr;
    for(const int& x: v) {
        if(head == nullptr)
            head = tail = new ListNode(x);
        else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }
    return head;
}
int main() {
    int n,m;
    cin >> n;
    vector<ListNode*> lists(n,nullptr);
    for(int index = 0; index < n; index++) {
        cin >> m;
        vector<int> v(m,0);
        ListNode *HEAD = nullptr, *TAIL = nullptr;
        for(int i = 0; i < m; i++) {
            cin >> v[i];
            if(HEAD == nullptr)
                HEAD = TAIL = new ListNode(v[i]);
            else {
                TAIL->next = new ListNode(v[i]);
                TAIL = TAIL->next;
            }
        }
        lists[index] = HEAD;
    }
    ListNode* head = mergeKLists(lists);
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}