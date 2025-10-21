/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || !cloned || !target) return nullptr;

        
        queue<TreeNode*> q;
        q.push(cloned);

        while (!q.empty()){
            int n = q.size();

            for (int i = 0 ; i < n ; i++){
                TreeNode* curr = q.front(); q.pop();

                if (curr->val == target->val) return curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return nullptr;
    }
};