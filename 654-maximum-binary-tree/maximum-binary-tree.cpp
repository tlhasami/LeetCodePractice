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
    TreeNode* built(vector<int>& nums , int low , int high) {
        if (low > high){
            return nullptr;
        }

        int maxVal = INT_MIN , maxIdx = -1;
        for (int i = low ; i <= high ; i++){
            if (maxVal < nums[i]){
                maxVal = nums[i];
                maxIdx = i;
            }
        }
            
        
        TreeNode* root = new TreeNode(maxVal);

        root->left = built(nums , low , maxIdx-1 );
        root->right = built(nums , maxIdx+1, high );
        
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return built(nums , 0 , nums.size()-1);
    }
};