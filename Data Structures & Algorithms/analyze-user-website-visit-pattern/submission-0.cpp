class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username,
                                      vector<int>& timestamp,
                                      vector<string>& website) {

        int n = username.size();

        // {timestamp, website}
        unordered_map<string, vector<pair<int, string>>> users;

        for (int i = 0; i < n; i++) {
            users[username[i]].push_back({timestamp[i], website[i]});
        }

        // pattern -> number of users
        map<vector<string>, int> count;

        for (auto &it : users) {
            auto visits = it.second;

            // Sort by timestamp
            sort(visits.begin(), visits.end());

            int m = visits.size();

            // Avoid counting same pattern twice for same user
            set<vector<string>> patterns;

            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    for (int k = j + 1; k < m; k++) {

                        vector<string> pattern = {
                            visits[i].second,
                            visits[j].second,
                            visits[k].second
                        };

                        patterns.insert(pattern);
                    }
                }
            }

            // Count this pattern for this user only once
            for (auto &p : patterns)
                count[p]++;
        }

        vector<string> ans;
        int best = 0;

        for (auto &it : count) {
            if (it.second > best) {
                best = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};