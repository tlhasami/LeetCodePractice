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
    void inorder(TreeNode* root , vector<int>& val){
        if(!root) return;

        inorder(root->left , val);
        val.push_back(root->val);
        inorder(root->right , val);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>val;
        inorder(root,val);

        int n = val.size();
        for (int i = 1 ; i < n ; i++){
            if (val[i-1] >= val[i])
                return false;
        }

        return true;
    }
};