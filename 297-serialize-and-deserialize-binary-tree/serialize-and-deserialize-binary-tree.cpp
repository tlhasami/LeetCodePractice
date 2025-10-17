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

    /*
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string result = to_string(root->val);

        queue<TreeNode*>q;
        q.push(root);

        while (!q.empty()){
            int n = q.size();

            for (int i = 0 ; i < n ; i++){
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left){
                    q.push(curr->left);
                    result.append(',' + to_string(curr->left->val));
                } else {
                    result.append(",null");
                }

                if (curr->right){
                    q.push(curr->right);
                    result.append(',' + to_string(curr->right->val));
                } else {
                    result.append(",null");
                }
            }
        }

        return result;

    }

    */

    string serialize(TreeNode* root) {
        if (!root) return "null";
        return to_string(root->val) +","+ serialize(root->left)+"," + serialize(root->right);
    }

    TreeNode* buildTree(vector<string>& nodes , int& idx){
        if (idx >= nodes.size() || nodes[idx] == "null"){
            idx++;
            return nullptr;
        }
        TreeNode* tree = new TreeNode(stoi(nodes[idx]));
        idx++;
        tree->left = buildTree(nodes, idx);
        tree->right = buildTree(nodes, idx);

        return tree;
    }

    // Result : 10,20,30,null,null,40,50,null,null,null,null
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        int index = 0;
        return buildTree(nodes, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));