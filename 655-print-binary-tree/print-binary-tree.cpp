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
    int getheight(TreeNode * root){
        if(!root) return 0;

        return 1 + max(getheight(root -> left), getheight(root -> right));
    }
    void solve(TreeNode * root, vector<vector<string>>&ans,int row,int left,int right){
        if(!root || left > right) return;
        int mid = (left + right)/2;
        ans[row][mid] = to_string(root -> val);
        solve(root -> left, ans, row + 1, left, mid -1);
        solve(root -> right, ans, row + 1, mid + 1, right);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getheight(root);
        int w = ( 1 << h) -1; // this we are doing to find number of columns
        vector<vector<string>> ans(h, vector<string>(w,""));
        solve(root , ans, 0 , 0, w-1);
        return ans;
    }
};