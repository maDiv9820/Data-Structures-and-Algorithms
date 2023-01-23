/*
Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [2,1,3]
Output: true

Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4. 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1

*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
vector<int> checkBST(TreeNode *root) {
    vector<int> allValues;
    if(root == NULL)
        return allValues;
    vector<int> left = checkBST(root->left);
    vector<int> right = checkBST(root->right);
    for(int x:left)
        allValues.push_back(x);
    allValues.push_back(root->val);
    for(int x:right)
        allValues.push_back(x);
    return allValues;
}
*/

bool isValidBST(TreeNode *root, int minVal = INT_MIN, int maxVal = INT_MAX) {
    /*
    Solution 1:- Time Complexity:- O(n)
                 Space Complexity:- O(n)
    vector<int> values = checkBST(root);
    for(int index = 0; index < values.size()-1; index++)
        if(values[index] > values[index+1])
            return false;
    return true;
    */
    /*
       Solution 2:- Time Complexity:- O(n)
                    Space Complexity:- O(n) 
    */
    if(root == NULL)
        return true;
    if(root->val >= minVal && root->val <= maxVal)
        return isValidBST(root->left,minVal,root->val) && isValidBST(root->right,root->val,maxVal);
    return false;
}

TreeNode* takeInput() {
    TreeNode *root = NULL;
    int n,left, right;
    cin >> n;
    if(n == -1)
        return root;
    root = new TreeNode(n);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        cin >> left >> right;
        if(left != -1) {
            TreeNode* leftT = new TreeNode(left);
            front->left = leftT;
            q.push(leftT);
        }
        if(right != -1) {
            TreeNode* rightT = new TreeNode(right);
            front->right = rightT;
            q.push(rightT);
        }
    }
    return root;
}

int main() {
    TreeNode* root = takeInput();
    cout << ((isValidBST(root) == 1) ? "true":"false") << endl;
}