class Solution {
public:
    int iterateProvince(vector<bool>&visited , vector<vector<int>>&list , const int& n , int i = 0){

        if (n == i) return 0;

        queue<int>qu;
        qu.push(i);
        visited[i] = true;
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
        }

        return 1;

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>>list(n);
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                //cout << isConnected[i][j] << " ";
                if (isConnected[i][j] == 1 && i!=j){
                    list[i].push_back(j);
                }
            }
        }

        // for (auto& l :list){
        //     for (auto& a : l){
        //         cout << a << " ";
        //     } cout << endl;
        // }



        vector<bool>visited(n,false);
        int count = 0;
        
        for (int i = 0 ; i < n ; i++){

            if (!visited[i])
                count+=iterateProvince(visited,list,n ,i);

            // for (bool a : visited) cout << a << " ";
            // cout << endl;
        }
        return count;
    }
};

/*
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor])
                dfs(neighbor, adj, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j)
                    adj[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                provinces++;
            }
        }
        return provinces;
    }
};
*/