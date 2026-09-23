class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;

        for(char c : text) {
            if(c=='b' || c=='a' || c=='l' || c=='o' || c=='n')
                mp[c]++;
        }

        return min({mp['b'], mp['a'], mp['l']/2, mp['o']/2, mp['n']});
    }
};