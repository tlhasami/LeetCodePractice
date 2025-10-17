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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int leftMost = root->val;
        while (!q.empty()){
            int level = q.size() ;

            leftMost = q.front()->val;
            for (int i = 0 ; i < level ; i++){
                TreeNode* curr = q.front() ; q.pop();

                
                if (curr->left) {
                    q.push(curr->left);
                    
                }
                if (curr->right) q.push(curr->right);
            }
        }

        return leftMost;
        
    }
};