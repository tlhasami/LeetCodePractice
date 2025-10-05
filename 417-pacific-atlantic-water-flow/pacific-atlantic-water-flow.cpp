class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int m , n ;

    void dfs(vector<vector<int>>& heights , vector<vector<bool>>& visited , int x , int y){
        
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newX >= m || newY < 0 || newY >= n || visited[newX][newY] ||
                heights[x][y] > heights[newX][newY])
                continue;
            else 
                dfs(heights , visited , newX , newY);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size() ;
        n = heights[0].size();
        vector<vector<bool>>pacific ( m , vector<bool>(n , false));
        vector<vector<bool>>atlantic ( m , vector<bool>(n , false));

        // rows
        for(int i = 0 ;i < m ;i++){
            dfs(heights , pacific , i ,0); // changed rows in first column -> Pacific
            dfs(heights , atlantic , i , n-1); // changed rows in last column -> Atlantic
        }

        for(int i = 0 ; i < n ; i++){
            dfs(heights , pacific , 0 ,i); // changed cols in first row -> Pacific
            dfs(heights , atlantic , m-1 , i); // changed cols in last row -> Atlantic
        }


        vector<vector<int>>result;

        for(int i = 0 ; i< m ;i++){
            for (int j = 0 ; j < n ; j++){
                if (pacific[i][j] && atlantic[i][j]) 
                    result.push_back({i,j});
            }
        }

        return result;

    }
};