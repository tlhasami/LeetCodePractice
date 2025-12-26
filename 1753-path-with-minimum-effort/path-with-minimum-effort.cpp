class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    struct Place{
        int cost;
        int row;
        int col;
        Place(int r=0,  int c =0, int co = 0)
            : row(r) , col(c) , cost(co) {}
    };

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size() , m = heights[0].size();

        auto cmp = [](Place& a, Place& b) { return a.cost > b.cost; };
        priority_queue<Place, vector<Place>, decltype(cmp)> minHeap(cmp);

        vector<vector<bool>>visited(n , vector<bool>(m , false));

        minHeap.push({0,0,0});

        while(!minHeap.empty()){
            Place temp = minHeap.top();
            minHeap.pop();

            if (visited[temp.row][ temp.col]) continue;
            visited[temp.row][ temp.col]= true;

            //cout << "Row: " << temp.row << " Col: " << temp.col << " Cost: " << temp.cost << endl;

            if (temp.row == n-1 && temp.col == m-1)
                return temp.cost;

            for (int i =0 ;i < 4 ; i++){
                int row = temp.row + dx[i];
                int col = temp.col + dy[i];

                if (row < 0 || row >= n || col < 0 || col >= m  )
                    continue;
                
                int toClimbCost = abs(heights[temp.row][temp.col]-heights[row][col]);
                minHeap.push({row,col, max(toClimbCost ,temp.cost)});


                //cout << "-> Row: " << row << " Col: " << col << " Cost: " << max(toClimbCost ,temp.cost) << endl;
            }
        }

        return -1;
                
    }
};