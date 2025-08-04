class Solution {
public:
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col) {
        visited[row][col] = true;

        for (int k = 0 ; k < 4 ; k++) {
            int nx = row + dx[k];
            int ny = col + dy[k];

            if (nx < 0 || ny < 0 || nx >= heights.size() || ny >= heights[0].size())
                continue;

            if (visited[nx][ny] || heights[nx][ny] < heights[row][col])
                continue;

            dfs(heights, visited, nx, ny);
        }
    }

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pac (heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> atl (heights.size(),vector<bool>(heights[0].size(),false));

        for (int i = 0 ; i < heights.size() ; i++){
            dfs(heights,pac,i,0);
            dfs(heights,atl,i,heights[0].size() - 1);
        }

        for (int i = 0 ; i < heights[0].size() ; i++){
            dfs(heights,pac,0,i);
            dfs(heights,atl,heights.size() - 1,i);
        }

        vector<vector<int>> ans;
        for (int i = 0 ; i < heights.size(); i++){
            for (int j = 0 ; j < heights[0].size() ; j++){
                if (atl[i][j] && pac[i][j]) 
                    ans.push_back({i,j});
            }
        }

        return ans;

    }
};