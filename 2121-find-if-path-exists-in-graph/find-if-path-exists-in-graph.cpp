class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>visited(n,false);
        vector<vector<int>>list(n);

        for (auto& edge : edges){
            list[edge[0]].push_back(edge[1]);
            list[edge[1]].push_back(edge[0]);
        }

        // for (auto& val : list){
        //     for (auto& num : val){
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        queue<int>qu;
        qu.push(source);
        visited[source] = true;
        while (!qu.empty()){
            int level = qu.size();

            for (int i = 0 ; i < level ; i++){
                int temp = qu.front() ; qu.pop();

                for (int& val : list[temp])
                    if (!visited[val]) {
                        visited[val] = true;
                        qu.push(val);
                    }
                
            }

            if (visited[destination]) return true;
        }

        return visited[destination] ;
    }
};
