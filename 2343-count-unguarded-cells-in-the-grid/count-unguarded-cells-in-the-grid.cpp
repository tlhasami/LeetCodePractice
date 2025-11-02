class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> space(m, vector<int>(n, 0));

        for (auto& wall : walls)
            space[wall[0]][wall[1]] = -1;

        for (auto& guard : guards)
            space[guard[0]][guard[1]] = 2;

        for (int i = 0; i < m; i++) {
            bool seen = false;
            for (int j = 0; j < n; j++) {
                if (space[i][j] == -1) seen = false;
                else if (space[i][j] == 2) seen = true;
                else if (seen) space[i][j] = 1;
            }
            seen = false;
            for (int j = n - 1; j >= 0; j--) {
                if (space[i][j] == -1) seen = false;
                else if (space[i][j] == 2) seen = true;
                else if (seen) space[i][j] = 1;
            }
        }

        for (int j = 0; j < n; j++) {
            bool seen = false;
            for (int i = 0; i < m; i++) {
                if (space[i][j] == -1) seen = false;
                else if (space[i][j] == 2) seen = true;
                else if (seen) space[i][j] = 1;
            }
            seen = false;
            for (int i = m - 1; i >= 0; i--) {
                if (space[i][j] == -1) seen = false;
                else if (space[i][j] == 2) seen = true;
                else if (seen) space[i][j] = 1;
            }
        }

        int count = 0;
        for (auto& row : space)
            for (int val : row)
                if (val == 0) count++;

        return count;
    }
};


/*
    void move(int X, int Y, const int& m,const int& n, vector<vector<int>>& space){
        for (int i = X-1; i >= 0 ; i--){
            if (space[i][Y] == -1)
                break;
            if (space[i][Y] == 0)
                space[i][Y] = 1;
        }

        for (int i = X+1 ; i < m ; i++){
            if (space[i][Y] == -1)
                break;
            
            if (space[i][Y] == 0)
                space[i][Y] = 1;
        }

        for (int j = Y-1 ; j >= 0 ; j--){
            if (space[X][j] == -1)
                break;
            if (space[X][j] == 0)
                space[X][j] = 1;
        }

        for (int j = Y+1 ; j < n ; j++){
            if (space[X][j] == -1)
                break;
            
            if (space[X][j] == 0)
                space[X][j] = 1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> space(m , vector<int>(n , 0));

        for (auto& wall : walls)
            space[wall[0]][wall[1]] = -1; // Wall

        for (auto& guard: guards){
            space[guard[0]][guard[1]] = 2; // guard
            move(guard[0] , guard[1] , m , n , space);

 
            for (auto& row : space){
                for (auto& val: row){
                    cout << setw(4)<< val ;
                } cout << endl;
            }
            cout << endl;
        }

        int count = 0;
        for (auto& row : space){
            for (auto& val: row){
                if (val ==0) count++;
            }
        }

        return count;
        
    }

    */