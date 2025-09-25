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
    void create(TreeNode* root, int& total, int curr) {
        if (!root) return;

        curr = curr * 10 + root->val;

        if (!root->left && !root->right) {
            total += curr;
            return;
        }

        create(root->left, total, curr);
        create(root->right, total, curr);
    }

    int sumNumbers(TreeNode* root) {
        int total = 0;
        create(root, total, 0);
        return total;
    }
};
