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
    void deorder(TreeNode* root , int& prev){
        if (!root) return ;

        deorder(root->right , prev);
        prev+=root->val;
        root->val = prev;
        deorder(root->left , prev);
    }
    TreeNode* convertBST(TreeNode* root) {
        int curr = 0;
        deorder(root ,curr );

        return root;
    }
};