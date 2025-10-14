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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return {};
        return build(1,n);
    }

    vector<TreeNode*> build(int low , int high){
        vector<TreeNode*>trees;

        if (low > high){
            trees.push_back(nullptr);
            return trees;
        }

        int mid = low + (high - low)/2 ;
        for (int i = low ; i <= high ;i++){
            vector<TreeNode*> leftTrees = build(low, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, high);

            for (auto left : leftTrees){
                for (auto right : rightTrees){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
};