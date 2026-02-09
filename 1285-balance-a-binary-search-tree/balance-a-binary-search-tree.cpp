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
    TreeNode* build(vector<int>& values , int left , int right ){
        if (left > right) return nullptr;

        int mid = (right-left) / 2 + left;
        // cout << left << " " << mid << " " << right << endl; 
        TreeNode* root = new TreeNode(values[mid]);

        root->left = build(values, left , mid-1);
        root->right = build(values, mid+1 , right);

        return root;
    }

    void inorder(TreeNode* root , vector<int>& values){
        if (!root) return ;

        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inorder(root, values);
        //return nullptr;
        return build(values , 0 , values.size()-1);
    }
};