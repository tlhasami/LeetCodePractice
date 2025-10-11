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

    string result = "~";
    void path (TreeNode* root , string current){
        if (!root) return;
        
        current.insert(current.begin(), 'a' + root->val);

        if (!root->left && !root->right) {
            if (current < result) result = current;
            return;
        }
        
        if (root->left)
            path(root->left ,current );
        if (root->right)
            path(root->right ,current );
    }

    string smallestFromLeaf(TreeNode* root) {
       if (!root) return "";
        
        path(root,"");

        return result;
    }
};