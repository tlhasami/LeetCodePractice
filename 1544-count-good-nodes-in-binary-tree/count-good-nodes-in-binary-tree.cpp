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
    int ans(TreeNode* root, int m) {
        if (!root) return 0;
        bool toAdd = root->val >= m;
        m = max(m, root->val);
        return (toAdd ? 1 : 0) + ans(root->left, m) + ans(root->right, m);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        return ans(root, root->val);
    }
};
