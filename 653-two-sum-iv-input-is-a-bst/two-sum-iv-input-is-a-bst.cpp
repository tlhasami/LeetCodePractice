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
        if (!root) return ;
        inorder(root->left , values);
        values.push_back(root->val);
        inorder(root->right , values);
    }
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        vector<int>values;
        inorder(root,values);

        unordered_map<int,int>freq;
        for (int& val : values){
            freq[val]++;
        }

        for (int& val : values){
            if (freq.find(k - val)!=freq.end() && (freq[k-val] > 2 || val != k-val) )
                return true;
        }

        return false;
    }
};