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
    int minDepth(TreeNode* root) {
        if (!root) return 0;


        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty()){
            int n = q.size();

            for (int i = 0 ; i<n ; i++){
                TreeNode* tree = q.front(); q.pop();

                if (tree->left) q.push(tree->left);
                if (tree->right) q.push(tree->right);

                if (!tree->left && !tree->right) return depth;
            }

            depth++;
        }


        return depth;
    }
};