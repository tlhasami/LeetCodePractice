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

    int val = 0;
    bool check(TreeNode* root){
        if (!root) return true;
        return val==root->val && check(root->left) && check(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return check(root);
    }
};