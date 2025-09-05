class Solution {
public:
    // Four possible directions: up, down, left, right
    int dx[4] = {-1, 1, 0, 0};  
    int dy[4] = {0, 0, -1, 1};

    bool visit(vector<vector<char>>& board,vector<vector<bool>>& visited  ,string word , int row , int col , int idx){
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() 
            || visited[row][col] || board[row][col] != word[idx]) {
            return false;
        }

        if (idx == word.length() - 1){
            return true;
        }

        visited[row][col] = true;

        

        for (int i = 0; i < 4; i++) {
            int newX = row + dx[i];
            int newY = col + dy[i];

            if (visit(board,visited,word,newX,newY,idx + 1)){
                return true;
            }
        }

        visited[row][col] = false;

        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size() , m = board[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (word[0] == board[i][j] && visit(board,visited,word,i,j,0) ){
                    return true;
                }
            }
        }

        return false;
    }
};