class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n);

        for (auto& time : times) {
            int u = time[0] - 1, v = time[1] - 1, w = time[2];
            graph[u].push_back({v, w});
        }

        k--;

        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); 
            pq.pop();

            if (d != dist[u])
                continue;

            for (auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int x : dist)
            if (x == INT_MAX) return -1;
            else ans = max(ans, x);

        return ans;
    }
};
