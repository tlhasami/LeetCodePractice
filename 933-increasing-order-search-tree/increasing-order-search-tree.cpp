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
    void inorder(TreeNode* root , TreeNode*& building){
        if (!root) return ;

        inorder(root->left,building);

        building->right = new TreeNode(root->val);
        building = building->right;

        inorder(root->right,building);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);  
        TreeNode* build = dummy;            
        inorder(root, build);
        return dummy->right;
    }
};