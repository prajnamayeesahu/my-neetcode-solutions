class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // dist[i] = minimum time to reach node (i+1)
        vector<int> dist(n, INT_MAX);

        // starting node k → time = 0
        dist[k - 1] = 0;

        // repeat n-1 times (relax edges)
        for (int i = 0; i < n - 1; ++i) {

            // go through all edges
            for (const auto& time : times) {

                int u = time[0] - 1; // from node
                int v = time[1] - 1; // to node
                int w = time[2];     // weight (time)

                // if u is reachable AND we found shorter path to v
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w; // update
                }
            }
        }

        // find the maximum time needed
        int maxDist = *max_element(dist.begin(), dist.end());

        // if any node unreachable → return -1
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};