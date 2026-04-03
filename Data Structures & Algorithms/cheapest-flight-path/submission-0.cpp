class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;

        // build graph
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<tuple<int,int,int>> q;
        q.push({src, 0, 0}); // node, cost, stops

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!q.empty()) {
            auto [node, cost, stops] = q.front();
            q.pop();

            if (stops > k) continue;

            for (auto& [nei, price] : adj[node]) {
                int newCost = cost + price;

                if (newCost < minCost[nei]) {
                    minCost[nei] = newCost;
                    q.push({nei, newCost, stops + 1});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
//bfs+cost tracking