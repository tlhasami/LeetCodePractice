class Solution { 
public:
    int sumTillLeaf(TreeNode* root , string currentBinary){
        if (!root)
            return 0;
        
        currentBinary += (root->val ? "1" : "0");

        // Correct leaf condition
        if (!root->left && !root->right){
            int value = 0;
            int n = currentBinary.length();

            for (int i = n-1 , power = 0 ; i >= 0 ; i-- , power++){
                if (currentBinary[i] == '1')
                    value += (1<<power); 
            }

            return value;
        }

        return sumTillLeaf(root->left , currentBinary) + 
               sumTillLeaf(root->right , currentBinary);
    }

    int sumRootToLeaf(TreeNode* root) {
        return sumTillLeaf(root,"");
    }
};