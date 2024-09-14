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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
        return buildTree(postorder, 0, postorder.size() - 1, 
                        inorder, 0, inorder.size() - 1, mp);
    }
    TreeNode* buildTree(vector<int> &postorder, int ps, int pe, 
                        vector<int> &inorder, int is, int ie, 
                        unordered_map<int,int> &mp)
    {
        if(ps>pe || is > is) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - is;
        root->left = buildTree(postorder, ps, ps + numsLeft - 1,
                                inorder, is, inRoot - 1, mp);
        root->right = buildTree(postorder, ps + numsLeft, pe - 1,
                                inorder, inRoot + 1, ie, mp);
        return root;
    }
};