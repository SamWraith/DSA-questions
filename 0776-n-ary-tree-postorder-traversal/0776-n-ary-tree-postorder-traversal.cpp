/*
// Definition for a Node.
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
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == NULL)
            return {};

        vector<int> ans;
        stack<Node*> st{{root}};

        while (!st.empty()) {
            root = st.top(), st.pop();
            ans.push_back(root->val);
            for (Node* child : root->children)
                st.push(child);
        }

        ranges::reverse(ans);
        return ans;
    }
};