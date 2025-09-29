class Solution {
public:
    int ans = 0;

    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0}; // {sum, count}

        auto [lsum, lcount] = dfs(root->left);
        auto [rsum, rcount] = dfs(root->right);

        int sum = lsum + rsum + root->val;
        int count = lcount + rcount + 1;

        if (sum / count == root->val) ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
