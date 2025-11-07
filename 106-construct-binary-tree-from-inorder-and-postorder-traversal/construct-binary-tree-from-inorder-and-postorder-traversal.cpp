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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int inStart , int inEnd , int postStart , int postEnd ) {

        if ( inStart>inEnd || postEnd < postStart ) return nullptr;

        TreeNode* tree = new TreeNode(postorder[postEnd]);

        int rootIndex = inStart ;
        while (rootIndex <= inEnd && inorder[rootIndex] != tree->val)
            rootIndex++ ;

        int count = rootIndex - inStart ;
        tree->left = build(inorder,postorder ,
                     inStart , rootIndex-1 ,
                     postStart , postStart + count - 1);

        tree->right = build(inorder,postorder ,
                     rootIndex+1 , inEnd ,
                     postStart + count , postEnd - 1);

        return tree;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};