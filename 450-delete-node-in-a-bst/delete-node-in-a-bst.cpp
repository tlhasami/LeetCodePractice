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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val == key){
            if (!root->left && !root->right){
                //TreeNode* toDelete = root;
                delete root;
                return nullptr;
            } else if (!root->left || !root->right) { 
                TreeNode* child = root->left ? root->left : root->right;
                delete root;
                return child;
            } else {
                TreeNode* successor = root->right;
                while (successor->left)
                    successor = successor->left;
                
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        } else if (root->val > key){
            root->left = deleteNode(root->left , key);
        } else if (root->val < key){
            root->right = deleteNode(root->right , key);
        }

        return root;
    }
};