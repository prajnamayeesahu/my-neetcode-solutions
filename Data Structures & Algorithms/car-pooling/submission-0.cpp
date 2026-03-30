class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        for (int i = 0; i < trips.size(); i++) {
            int curPass = trips[i][0];
            for (int j = 0; j < i; j++) {
                if (trips[j][2] > trips[i][1]) {
                    curPass += trips[j][0];
                }
            }
            if (curPass > capacity) {
                return false;
            }
        }
        return true;
    }
};
