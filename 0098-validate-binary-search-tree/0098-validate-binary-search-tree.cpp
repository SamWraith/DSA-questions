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
private:
    bool solve(TreeNode* root, long long int min, long long int max){
        if(root == NULL) return true;
        if(root->val >= max || root->val <= min) return false;
        bool left = solve(root->left, min, root->val);
        bool right = solve(root->right, root->val, max);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, -4294967296, 4294967296);
    }
};