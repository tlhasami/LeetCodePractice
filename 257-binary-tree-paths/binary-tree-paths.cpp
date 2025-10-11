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
    vector<string>result;

    void traversal(TreeNode* root , string path){
        if (!root) {
            return;
        }

        path += "->" + to_string(root->val);

        traversal(root->left , path);
        traversal(root->right, path);

        if (!root->left && !root->right){
            result.push_back(path);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};

        if (!root->left && !root->right){
            result.push_back(to_string(root->val));

            return result;
        }
            
        traversal(root->left , to_string(root->val));
        traversal(root->right,to_string(root->val) );

        return result;
    }
};