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
        if (n == 0) return {};
        return build(1 , n);
    }

    vector<TreeNode*> build(int low, int high){
        vector<TreeNode*>trees;
        if (low > high){
            trees.push_back(nullptr);
            return trees;
        }

        for (int val = low ; val <= high ; val++){

            vector<TreeNode*> LeftTrees = build(low , val - 1);
            vector<TreeNode*> RightTrees = build(val + 1 ,high);

            for (auto L : LeftTrees){
                for (auto R : RightTrees){
                    TreeNode* root = new TreeNode(val);

                    root->left = L;
                    root->right = R;
                    
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }



};