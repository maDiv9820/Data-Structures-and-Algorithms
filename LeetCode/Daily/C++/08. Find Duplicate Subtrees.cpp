/*
Find Duplicate Subtrees

Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:

Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:

Input: root = [2,1,1]
Output: [[1]]

Example 3:

Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:

    The number of the nodes in the tree will be in the range [1, 5000]
    -200 <= Node.val <= 200
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
string getNumber(int val) {
    if(val == 0)
        return "0";
    string s = "";
    bool isneg = false;
    if(val < 0) {
        isneg = true;
        val = abs(val);
    }
    while(val > 0) {
        int r = val%10;
        char ch = '0'+r;
        s = ch+s;
        val /= 10;
    }
    if(isneg)
        s = '-'+s;
    return s;
}
string traverse(TreeNode* root, vector<TreeNode*>& d, map<string, vector<TreeNode*>*>& m) {
    if(!root)
        return "null";
    string s1 = getNumber(root->val), s2 = traverse(root->left,d,m), s3 = traverse(root->right,d,m);
    string path = s1 + ' ' + s2 + ' ' + s3;
    if(m.count(path) == 1 && m[path]->size() == 1)
        d.emplace_back(root);
    
    if(m.count(path) == 0)
        m[path] = new vector<TreeNode*>(0);
    m[path]->emplace_back(root);
    return path;
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> d;
    map<string,vector<TreeNode*>*> m;
    string s = traverse(root,d,m);
    return d;
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
void traverse(TreeNode* root) {
    if(!root)
        return;
    cout << root->val << " ";
    traverse(root->left);
    traverse(root->right);
}
int main() {
    TreeNode* root = takeInput();
    vector<TreeNode*> duplicates = findDuplicateSubtrees(root);
    for(auto val: duplicates) {
        traverse(val);
        cout << endl;
    }
}