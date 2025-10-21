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
    void inorder(TreeNode* root , vector<int>& values){
        if (!root) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

    int count(TreeNode* root){
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    TreeNode* make(vector<int>& values , int low, int high){
        if (low > high) return nullptr;

        int mid = low + (high-low)/2;

        TreeNode* root = new TreeNode(values[mid]);
        root->left = make(values,low, mid-1);
        root->right = make(values,mid+1, high);
        
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>values;
        values.reserve(count(root));
        inorder(root,values);

        TreeNode* result = make(values,0,values.size()-1);

        return result;
    }
};