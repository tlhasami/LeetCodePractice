class Solution {
public:
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
    
    }
};