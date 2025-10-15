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
    /*
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*>q;

        q.push(root);

        int sum = 0;
        while (!q.empty()){
            int size = q.size();

            for (int i = 0 ; i < size ; i++){
                TreeNode* current = q.front(); q.pop();
                if (current->left && !current->left->left && !current->left->right) {
                    sum+= current->left->val;
                }

                if (current->left)
                    q.push(current->left);

                if (current->right)
                    q.push(current->right);
            }
        }

        return sum;

    }
    */
    int sum = 0;
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        
        if (root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);

    }
};