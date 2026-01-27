class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adjencyList(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adjencyList[u].push_back({w, v});       // u -> v (w)
            adjencyList[v].push_back({w * 2, u});   // v -> u (2w)
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});   // {distance, node}

        while (!pq.empty()) {
            int currDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (currDist > dist[u])
                continue;

            for (auto edge : adjencyList[u]) {
                int weight = edge.first;
                int v = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
