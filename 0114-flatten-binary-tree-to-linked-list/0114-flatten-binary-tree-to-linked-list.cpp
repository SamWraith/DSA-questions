/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // recursive
    void solve(TreeNode* node, TreeNode* &prev){
        if(node == NULL) return;
        solve(node->right, prev);
        solve(node->left, prev);
        node->right = prev;
        node->left = NULL;
        prev = node;
    }
    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;
        solve(root, prev);
    }
};