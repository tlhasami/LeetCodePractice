class Solution {
public:

    void dfs(vector<vector<int>>& graph , vector<vector<int>>& result , vector<int>&path ,vector<bool>&visited, const int& n , int idx = 0 ){

        visited[idx] = true;
        path.push_back(idx);

        if (idx == n){
            result.push_back(path);
        }
        
        for (int& edge : graph[idx] )
            if (!visited[edge]) 
                dfs(graph ,result,path,visited,n,edge);
            
        visited[idx] = false;
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>result;
        vector<bool>visited( graph.size() , false);
        vector<int>path;
        //dfs(graph,result,path, visited,graph.size()-1 , 0);

        queue<vector<int>>qu;

        qu.push({0});

        int n = graph.size();

        while(!qu.empty()){
            vector<int> top = qu.front() ; qu.pop();

            int idx = top.back();

            if (idx == n -1) {
                result.push_back(top);
                continue;
            }

            for (int& edge : graph[idx]){
                if(!visited[edge]){
                    top.push_back(edge);
                    qu.push(top) ;
                    top.pop_back();
                }
            }
        }

        return result;
        
    }
};