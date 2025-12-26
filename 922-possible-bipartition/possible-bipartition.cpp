class Solution {
public:
    bool bfs(const int& numberOfPeoples, vector<vector<int>>& graph , vector<char>&colors , int node ){
        queue<int>qu;
        qu.push(node);
        colors[node] = 'A';

        while (!qu.empty()){
            int u = qu.front();
            qu.pop();

            for (auto& v : graph[u]){
                if (colors[v] == '.'){
                    colors[v] = colors[u] == 'A' ? 'B':'A'; 
                    qu.push(v);
                } else if (colors[v] == colors[u]) {
                    return false;
                }
            }
        }

        return true;

    }
    bool possibleBipartition(int numberOfPeoples, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(numberOfPeoples);

        int n = dislikes.size();
        for (int i = 0 ; i < n ; i++){
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }

        vector<char>colors(numberOfPeoples,'.');

        for (int u = 0 ; u < numberOfPeoples ; u++){
            if (colors[u] == '.' && !bfs(numberOfPeoples , graph, colors , u))
                return false;
        }

        return true;        
    }
};