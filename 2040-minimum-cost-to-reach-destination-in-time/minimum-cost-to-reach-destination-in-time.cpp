class Solution {
public:
    struct node {
        int u;
        int cost;
        int time;
        node(int a =0,  int b=0 , int c=0) : u(a) , cost(b) , time(c) {}
    };



    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        
        auto cmp = [](const node& a, const node& b) {
            if (a.cost == b.cost)
                return a.time > b.time;   // min time
            return a.cost > b.cost;       // min cost
        };
        int numberOfStops = passingFees.size();

        vector<vector<pair<int,int>>>graph(numberOfStops );
        for (auto& edge : edges){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }

        // for (int i = 0 ; i < numberOfStops ; i++){
        //     cout << i << "-> ";
        //     for (auto& list: graph[i])
        //         cout << "{"<< list.first  << "," << list.second << "} ";
        //     cout << endl;
        // }


        priority_queue<node, vector<node>, decltype(cmp)> qu(cmp);
        vector<int>visited(numberOfStops , 0);

        vector<vector<int>> best(numberOfStops, vector<int>(maxTime + 1, INT_MAX));
        
        best[0][0] = passingFees[0];
        qu.push({0, passingFees[0], 0});

        while (!qu.empty()) {
            node temp = qu.top();
            qu.pop();

            if (temp.u == numberOfStops - 1)
                return temp.cost;

            for (auto& [v, w] : graph[temp.u]) {
                int newTime = temp.time + w;
                if (newTime > maxTime) continue;

                int newCost = temp.cost + passingFees[v];

                if (newCost < best[v][newTime]) {
                    best[v][newTime] = newCost;
                    qu.push({v, newCost, newTime});
                }
            }
        }


        return -1;
    }
};