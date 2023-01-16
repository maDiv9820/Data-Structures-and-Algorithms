/*
Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    /*
        Solution: Use Merge Algo
        Time Complexity: O(n)
        Space Complexity: O(1)
    */
    if(list1 && list2) {    
        ListNode *head = NULL, *tail = NULL;
        if(list1->val <= list2-> val) {
            head = tail = list1;
            list1 = list1->next;
        }
        else {
            head = tail = list2;
            list2 = list2->next;
        }

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        while(list1) {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        while(list2) {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
        return head;
    }
    else if(list1)
        return list1;
    else
        return list2;
}

int main() {
    ListNode *h1 = NULL, *h2 = NULL, *t1 = NULL, *t2 = NULL;
    int n;
    cin >> n;
    while(n!= 0) {
        if(h1 == NULL) {
            h1 = new ListNode(n);
            h1 = t1;
        }
        else {
            t1->next = new ListNode(n);
            t1 = t1->next;
        }
        cin >> n;
    } 
    cin >> n;
    while(n != 0) {
        if(h2 == NULL) {
            h2 = new ListNode(n);
            h2 = t2;
        }
        else {
            t2->next = new ListNode(n);
            t2 = t2->next;
        }
        cin >> n;
    }
    ListNode* mergeList = mergeTwoLists(h1,h2);
    while(mergeList) {
        cout << mergeList->val << " ";
        mergeList = mergeList->next;
    }
    cout << endl;
}