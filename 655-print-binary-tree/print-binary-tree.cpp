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
    vector<vector<string>> result;
    void place(TreeNode* root , int r  , int start , int end){
        if (!root) return ;

        int mid = start + (end - start)/2;
        cout << start << " " << end << " " << mid << endl;
        result[r][mid] = to_string(root->val);

        place(root->left , r+1 , start , mid-1 );
        place(root->right , r+1 ,mid+1 , end );
    }
    */

    int getHeight(TreeNode* root){
        if (!root) return 0;
        return 1 + max(getHeight(root->left) ,getHeight(root->right) );
    }

    vector<vector<string>> result;
    void place(TreeNode* root , int r  , int c ,const int& height){
        if (!root) return ;
        result[r][c] = to_string(root->val);
        if (r+1 == result.size()) return ;

        place(root->left , r+1 , c - pow(2,height-r-2) , height);
        place(root->right , r+1 , c + pow(2,height-r-2) , height );
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int width = pow(2 , height) - 1;

        cout << height << " " << width << endl;

        result = vector<vector<string>>(height , vector<string>(width , ""));
        place(root,0,(width-1)/2,height);

        return result;

    }
};