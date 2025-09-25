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
    vector<int>curr;
    void path(TreeNode* root, int targetSum ,vector<vector<int>>& result, int current , vector<int>&curr) {
        if (!root) return;

        curr.push_back(root->val);

        if (current+root->val == targetSum && !root->left && !root->right) {
            result.push_back(curr);
            curr.pop_back();
            return;   
        }


        path(root->left,targetSum,result,current + root->val,curr);
        path(root->right,targetSum,result,current + root->val,curr);

        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;

        path(root,targetSum,result,0,curr);

        return result;
    }
};