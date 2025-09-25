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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        stack<vector<int>>st;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            vector<int>curr;
            curr.reserve(size);
            for (int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front(); q.pop();

                curr.push_back(temp->val);
                if (temp->left)q.push(temp->left);
                if (temp->right)q.push(temp->right);

            }

            st.push(curr);

        }

        vector<vector<int>>result;
        result.reserve(st.size());

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};