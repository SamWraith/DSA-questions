/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist++ == k) break;
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                // left
                if(node->left && !vis[node->left]){
                    vis[node->left] = true;
                    q.push(node->left);
                }
                //right
                if(node->right && !vis[node->right]){
                    vis[node->right] = true;
                    q.push(node->right);
                }
                // parent
                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }
        return res;
    }
};