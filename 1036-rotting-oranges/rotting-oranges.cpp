class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        int fresh = 0 ;
        queue<pair<int,int>>q;

        for(int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] == 2){
                    q.push({i,j});
                }else if (grid[i][j] == 1) {
    fresh++;
}
            }
        }


        if (fresh==0) return 0;

        int minutes = -1;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int sz = q.size();
            minutes++;


            for (int i = 0 ; i < sz ; i++){
                auto [x, y] = q.front();
                 q.pop();
                 for(int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2; // rot it
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }

        }

        return fresh == 0 ? minutes : -1;

    }
};