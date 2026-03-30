class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // Attach original index
        for (int i = 0; i < n; ++i) {
            tasks[i].push_back(i);
        }

        // Sort by enqueue time
        sort(tasks.begin(), tasks.end());

        // Min-heap: {processingTime, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> result;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {

            // If heap empty, jump time to next task
            if (pq.empty() && time < tasks[i][0]) {
                time = tasks[i][0];
            }

            // Push all available tasks
            while (i < n && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // Process smallest job
            auto [procTime, index] = pq.top();
            pq.pop();

            time += procTime;
            result.push_back(index);
        }

        return result;
    }
};