class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>&visited , int node ){
        if (visited[node] == 1)
            return false;
        if (visited[node] == 2)
            return true;

        visited[node] = 1;
        for (int& v : graph[node]){
            if (!dfs(graph,visited,v))
                return false;
        }

        visited[node] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numberOfNodes = graph.size();

        vector<int>result;
        vector<int>visited(numberOfNodes,0);

        for (int i = 0 ; i < numberOfNodes ; i++){
            if (dfs(graph,visited,i))
                result.push_back(i);
        }

        return result;
       
    }
};

/*

        int numberOfNodes = graph.size();
        vector<vector<int>>inversedGraph(numberOfNodes);
        vector<int>outDegree(numberOfNodes) , safeNodes;

        vector<bool>safe(numberOfNodes , false);

        queue<int>qu;

        for (int i=0 ; i < numberOfNodes ; i++){
            int numberOfEdges = graph[i].size();

            outDegree[i] = numberOfEdges;

            for (int j = 0 ; j < numberOfEdges ; j++){
                inversedGraph[graph[i][j]].push_back(i);
            }

            if (outDegree[i] == 0)
                qu.push(i);
        }



        while (!qu.empty()){
            int temp = qu.front();
            qu.pop();
            safe[temp] = true;

            for (int& parent : inversedGraph[temp]){
                --outDegree[parent];
                
                if (outDegree[parent] == 0)
                    qu.push(parent);
            }
        }

        for(int i = 0 ; i < numberOfNodes ; i++)
            if (safe[i])
                safeNodes.push_back(i);
        
        return safeNodes;



*/