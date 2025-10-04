class Solution {
public:
    int firstMin, secMin;
    bool found = false;
    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (root->val < firstMin) {
            secMin = firstMin;
            firstMin = root->val;
            found = true;
        }
        else if (root->val > firstMin && root->val <= secMin) {
            secMin = root->val;
            found = true;
        }

        inorder(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        firstMin = root->val;      // root is always the smallest (per problem statement)
        secMin = INT_MAX;

        inorder(root);

        return ( !found ? -1 : secMin);
    }
};
