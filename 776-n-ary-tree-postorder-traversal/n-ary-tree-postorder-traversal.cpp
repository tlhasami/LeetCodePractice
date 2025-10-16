/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorder(Node* root , vector<int>& val){
        if (!root) return;

        for (auto child : root->children){
            postorder(child , val);
        }
        val.push_back(root->val);
        
    }

    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int>val;
        postorder(root,val);
        return val;
    }
};