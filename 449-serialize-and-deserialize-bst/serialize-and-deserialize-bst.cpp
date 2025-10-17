/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        return serialize(root->left) + "," + serialize(root->right) + "," + to_string(root->val); 
    }

    TreeNode* build(vector<string>& nodes , int& idx){
        if (idx < 0 || nodes[idx] == "null"){
            idx--;
            return nullptr;
        }

        TreeNode* tree = new TreeNode(stoi(nodes[idx]));
        idx--;
        tree->right = build(nodes , idx);
        tree->left = build(nodes , idx);

        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string part ;
        while (getline(ss,part,',')){
            nodes.push_back(part);
        }
        int idx = nodes.size()-1;
        return build(nodes , idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;