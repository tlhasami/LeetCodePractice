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
    int low,high;

    void inorder(TreeNode* root , int& rangeSum){
        if (!root) return ;

        inorder(root->left,rangeSum);
        inorder(root->right,rangeSum);

        if(low <= root->val && high >= root->val) rangeSum+=root->val;

    }
    
    int rangeSumBST(TreeNode* root, int l, int h) {
        int rangeSum = 0;
        low = l, high = h;
        inorder(root , rangeSum);

        return rangeSum;
    }
};