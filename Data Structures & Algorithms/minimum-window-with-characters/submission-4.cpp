class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        for(char c : t) {
            mp[c]++;
        }

        int l = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int start = 0;

        for(int r = 0; r < s.size(); r++) {
            if(mp[s[r]] > 0)
                count--;
            mp[s[r]]--;
            while(count == 0) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0)
                    count++;

                l++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};