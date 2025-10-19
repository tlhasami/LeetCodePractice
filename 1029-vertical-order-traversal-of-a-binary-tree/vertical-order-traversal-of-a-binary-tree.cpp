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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}}); // {node, {col, row}}
        vector<tuple<int,int,int>> values; // {col, row, val}

        while (!q.empty()) {
            auto [node, pos] = q.front(); q.pop();
            int col = pos.first, row = pos.second;
            values.push_back({col, row, node->val});

            if (node->left)  q.push({node->left,  {col - 1, row + 1}});
            if (node->right) q.push({node->right, {col + 1, row + 1}});
        }


        sort(values.begin(), values.end(), [](auto &a, auto &b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        });

        int left = INT_MAX, right = INT_MIN;
        for (auto &t : values) {
            left = min(left, get<0>(t));
            right = max(right, get<0>(t));
        }

        int size = right - left + 1;
        vector<vector<int>> result(size);
        int offset = -left;

        // Fill result
        for (auto &[col, row, val] : values) {
            result[col + offset].push_back(val);
        }

        return result;
    }
};
