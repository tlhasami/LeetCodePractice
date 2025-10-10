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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*>q;
        vector<int> values;

        q.push(root);

        while (!q.empty()){
            int size = q.size();

            TreeNode* temp = nullptr;
            for (int i = 0 ; i < size ; i++){
                temp = q.front() ; q.pop();

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            values.push_back(temp->val);

        }

        return values;
    }
};