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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        
        queue<TreeNode*>qu;
        qu.push(root);
        

        while(!qu.empty()){
            int levelSize = qu.size();       
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = qu.front();
                qu.pop();

                currentLevel.push_back(node->val);

                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);

            }

            result.push_back(currentLevel);

        }

        return result;
        
    }
};