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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*>q;
        q.push(root);

        bool odd = false;
        while(!q.empty()){
            int size = q.size();

            vector<TreeNode*>toSwap;

            for (int i = 0 ; i < size ; i++){
                TreeNode* temp = q.front(); q.pop();
                toSwap.push_back(temp);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            if (odd){
                int left = 0 , right = toSwap.size() - 1;
                while (left < right){
                    swap(toSwap[left++]->val ,toSwap[right--]->val);
                }
            }

            odd = !odd;
        }
        

        return root;
    }
};