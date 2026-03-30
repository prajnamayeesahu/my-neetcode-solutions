class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int maxLen=0;
        unordered_set<char> hash;
        for(int r=0;r<s.length();r++) {
            while(hash.find(s[r]) != hash.end()) {
                hash.erase(s[l]);
                l++;
            }
            hash.insert(s[r]);
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};

//brute force
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) { 
//         int n = s.length();
//         int maxLan = 0;
//         for(int i=0;i<n;i++) {
//             unordered_set<char> hash;
//             for(int j=i;j<n;j++) {
//                 if(hash.count(s[j])) break;
//                 hash.insert(s[j]);
//                 maxLan=max(maxLan,j-i+1);
//             }
//         }
//         return maxLan;
//     }
// };