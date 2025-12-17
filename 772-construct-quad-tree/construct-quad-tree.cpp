/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

private:
    Node* build(const vector<vector<int>>& grid, int i, int j, int w) {
        if (isUniform(grid, i, j, w))
            return new Node(grid[i][j], true);

        Node* root = new Node(true, false);
        int half = w / 2;

        root->topLeft = build(grid, i, j, half);
        root->topRight = build(grid, i, j + half, half);
        root->bottomLeft = build(grid, i + half, j, half);
        root->bottomRight = build(grid, i + half, j + half, half);

        return root;
    }

    bool isUniform(const vector<vector<int>>& grid, int i, int j, int w) {
        int val = grid[i][j];
        for (int x = i; x < i + w; x++)
            for (int y = j; y < j + w; y++)
                if (grid[x][y] != val)
                    return false;
        return true;
    }
};