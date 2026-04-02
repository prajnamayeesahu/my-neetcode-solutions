class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX); // min cost to connect
        vector<bool> visited(n, false);  // already in MST

        minDist[0] = 0; // start from point 0

        int result = 0;

        for(int i = 0; i < n; i++) {

            // 1. pick minimum unvisited node
            int u = -1;
            for(int j = 0; j < n; j++) {
                if(!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            // 2. include it
            visited[u] = true;
            result += minDist[u];

            // 3. update distances
            for(int v = 0; v < n; v++) {
                if(!visited[v]) {
                    int dist = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);

                    if(dist < minDist[v]) {
                        minDist[v] = dist;
                    }
                }
            }
        }

        return result;
    }
};