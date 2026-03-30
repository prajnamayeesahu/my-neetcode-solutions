class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        
        vector<int> sides(4, 0);
        return dfs(matchsticks, sides, 0);
    
    }
    //back track
    private:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int i) {
        if (i == matchsticks.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }

        for (int j = 0; j < 4; j++) {
            sides[j] += matchsticks[i];
            if (dfs(matchsticks, sides, i + 1)) return true;
            sides[j] -= matchsticks[i];
        }

        return false;
    }
};