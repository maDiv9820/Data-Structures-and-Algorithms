/*
Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list. 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: [] 

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

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

pair<ListNode*,ListNode*> reverse(ListNode* list) {
    if(list == NULL) {
        ListNode *head = NULL, *tail = NULL; 
        return make_pair(head,tail);
    }
    ListNode* firstNode = list;
    ListNode* nextpart = list->next;
    list->next = NULL;
    pair<ListNode*,ListNode*> reversedList = reverse(nextpart);
    ListNode *head = reversedList.first, *tail = reversedList.second;
    if(head == NULL) {
        head = tail = firstNode;
    }
    else {
        tail->next = firstNode;
        tail = firstNode;
    }
    return make_pair(head,tail);
}

ListNode* reverseList(ListNode* list) {
    /*
        Solution 1: Using Recursion
        Time Complexity: O(n)
        Space Complexity: O(n)
        where n is the size of the List
    
    pair<ListNode*,ListNode*> ans = reverse(list);
    return ans.first;
    */
    /*
        Solution 2: Using Iteration
        Time Complexity:- O(n)
        Space Complexity:- O(1)
        where n is the size of the list
    */
    ListNode *head = list, *tail = NULL;
    while(head) {
        ListNode* nextNode = head->next;
        head->next = tail;
        tail = head;
        head = nextNode;
    }
    return tail;
}

int main() {
    ListNode *h = NULL, *t = NULL;
    int n;
    cin >> n;
    while(n != 0) {
        if(h == NULL) {
            h = t = new ListNode(n);
        }
        else {
            t->next = new ListNode(n);
            t = t->next;
        }
        cin >> n;
    }
    ListNode* reversedList = reverseList(h);
    while(reversedList) {
        cout << reversedList->val << " ";
        reversedList = reversedList->next;
    }
    cout << endl;
}