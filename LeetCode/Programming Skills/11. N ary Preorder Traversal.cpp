/*
N-ary Tree Preorder Traversal

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal. 
Each group of children is separated by the null value (See examples)

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]


Constraints:

    The number of nodes in the tree is in the range [0, 104].
    0 <= Node.val <= 104
    The height of the n-ary tree is less than or equal to 1000.
*/
#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};
vector<int> preorder(Node* root) {
    vector<int> v;
    if(root == NULL)
        return v;
    v.push_back(root->val);
    for(int index = 0; index < root->children.size(); index++) {
        vector<int> children = preorder(root->children[index]);
        for(int x: children)
            v.push_back(x);
    }
    return v;
}
int main() {
    int n;
    Node *root = NULL;
    cin >> n;
    while(n != -1) {
        if(root == NULL)
            root = new Node(n);
        else {
            Node* newNode = new Node(n);
            root->children.push_back(newNode);            
        }
        cin >> n;
    }
    vector<int> v = preorder(root);
    for(int x: v)
        cout << x << " ";
    cout << endl;
}