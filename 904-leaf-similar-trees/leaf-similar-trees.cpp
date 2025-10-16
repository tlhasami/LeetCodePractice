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
    void getLeaves(TreeNode* root, vector<int>& val){
        if (!root) return;

        if (!root->left && !root->right){
            val.push_back(root->val);
            return;
        }

        getLeaves(root->left,val);
        getLeaves(root->right,val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return false;

        vector<int> values1 , values2 ;

        getLeaves(root1 , values1);
        getLeaves(root2 , values2);

        if (values1.size() != values2.size()) return false;

        return values1 == values2;
    }
};