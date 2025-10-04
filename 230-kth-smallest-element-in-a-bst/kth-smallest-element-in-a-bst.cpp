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
    int result = 0;
    void inorder(TreeNode* root , int k , int& curr ){
        if (!root) return;

        inorder(root->left , k , curr);
        if (curr == k-1) 
            result = root->val;
        curr++;
        inorder(root->right , k , curr);
    }
    int kthSmallest(TreeNode* root, int k) {
        int curr = 0;
        inorder(root,k,curr);
        return result;
    }
};