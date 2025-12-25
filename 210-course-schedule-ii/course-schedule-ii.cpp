class Solution {
public:
    bool dfs(vector<vector<int>>&graph ,vector<int>&visited , stack<int>&st , int node ){
        if (visited[node] == 1)
            return false;
        if (visited[node] == 2)
            return true;

        visited[node] = 1;
        for (auto& v : graph[node])
            if (!dfs(graph,visited,st,v))
                return {};
        
        visited[node] = 2;
        st.push(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>topo;
        vector<vector<int>>graph(numCourses);

        for (auto& pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }

        for (auto& adjencylist : graph){
            for (int& node :adjencylist){
                indegree[node]++;
            }
        }

        stack<int>st;
        vector<int>visited(numCourses,0);

        for (int i = 0 ; i < numCourses ; i++){
            if (!visited[i] )
                if(!dfs(graph,visited,st,i))
                    return {};
        }

        while (!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }

        return topo;    
    }
};

/*
        queue<int>qu;
        for (int i = 0 ; i < numCourses ; i++)
            if (indegree[i] == 0)
                qu.push(i);
        
        while(!qu.empty()){
            int temp = qu.front();
            qu.pop();

            topo.push_back(temp);

            for (auto& node : graph[temp] ){
                --indegree[node];
                if (indegree[node] == 0)
                    qu.push(node);
            }
        }

        if (topo.size() == numCourses)
            return topo;
        
        return {};
*/