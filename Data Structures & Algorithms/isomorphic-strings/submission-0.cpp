class Solution {
private:
    bool helper(const string& s, const string& t) {
        unordered_map<char, char> map;
        for (int i = 0; i < s.length(); i++) {
            if (map.count(s[i]) && map[s[i]] != t[i]) {
                return false;
            }
            map[s[i]] = t[i];
        }
        return true;
    }

public:
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t, s);
    }
};

