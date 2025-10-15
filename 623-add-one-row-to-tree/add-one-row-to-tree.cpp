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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) return nullptr;

        if (depth == 1){
            TreeNode* tree = new TreeNode(val);
            tree->left = root;
            root = tree;
            return root;
        }

        depth --;
        queue<TreeNode*>q;
        q.push(root); 

        while (!q.empty()){
            int size = q.size(); 
            for (int i = 0 ; i < size ; i++){
                TreeNode* tree = q.front(); 
                q.pop();

                if (depth == 1){
                    TreeNode* toAddLeft = new TreeNode(val);
                    toAddLeft->left = tree->left;
                    TreeNode* toAddRight = new TreeNode(val);
                    toAddRight->right = tree->right;

                    tree->left = toAddLeft;
                    tree->right = toAddRight;
                }


                if (tree->left) q.push(tree->left);
                if (tree->right) q.push(tree->right);
            }

            if (depth == 1) return root;

            depth --;
        }

        return root;

    }
};