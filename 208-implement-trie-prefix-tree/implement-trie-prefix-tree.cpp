class Trie {
public:
    struct TreeNode {
        char alphabet;
        vector<TreeNode*> characters;
        bool isEnd;

        TreeNode(char key = '\0') : alphabet(key), isEnd(false) {
            characters = vector<TreeNode*>(26, nullptr);
        }
    };

    TreeNode* top;

    Trie() {
        top = new TreeNode();
    }

    void insertHelper(TreeNode* root, const string& word, int index) {
        if (index == word.length()) {
            root->isEnd = true;
            return;
        }

        int pos = word[index] - 'a';
        if (root->characters[pos] == nullptr) {
            root->characters[pos] = new TreeNode(word[index]);
        }

        insertHelper(root->characters[pos], word, index + 1);
    }

    void insert(string word) {
        insertHelper(top, word, 0);
    }

    bool search(string word) {
        TreeNode* root = top;
        int index = 0, n = word.length();

        while (root && index < n) {
            TreeNode* temp = root->characters[word[index] - 'a'];
            if (temp == nullptr) return false;
            root = temp;
            index++;
        }

        return (root && root->isEnd);
    }

    bool startsWith(string prefix) {
        TreeNode* root = top;
        int index = 0, n = prefix.length();

        while (root && index < n) {
            TreeNode* temp = root->characters[prefix[index] - 'a'];
            if (temp == nullptr) return false;
            root = temp;
            index++;
        }

        return (root != nullptr);
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */