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

    bool helper(TreeNode* root, int targetSum , int current = 0) {
        if (!root) return false;

        current += root->val;

        if (!root->left && !root->right)
            return current == targetSum;
        

        return helper(root->left,targetSum,current ) || helper(root->right,targetSum,current) ;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return helper(root,targetSum) ;
    }
};