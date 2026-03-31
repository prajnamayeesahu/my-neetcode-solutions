class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        pq.push({0, {0,0}});
        dist[0][0] = 0;

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();

            int r = pos.first;
            int c = pos.second;

            if(r == n-1 && c == m-1)
                return effort;

            for(auto& d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr<0 || nc<0 || nr>=n || nc>=m)
                    continue;

                int newEffort = max(effort,
                    abs(heights[r][c] - heights[nr][nc]));

                if(newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, {nr,nc}});
                }
            }
        }

        return 0;
    }
};