class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> words(dictionary.begin(), dictionary.end());
        return dfs(0, s, words);
    }

private:
    int dfs(int i, const string& s, unordered_set<string>& words) {
        if (i == s.size()) {
            return 0;
        }

        int res = 1 + dfs(i + 1, s, words);
        for (int j = i; j < s.size(); j++) {
            if (words.count(s.substr(i, j - i + 1))) {
                res = min(res, dfs(j + 1, s, words));
            }
        }

        return res;
    }
};