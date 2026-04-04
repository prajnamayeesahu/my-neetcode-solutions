class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < s.size() &&
                   s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }

            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() &&
                   s[l] == s[r]) {
                cnt++;
                l--;
                r++;
            }
        }

        return cnt;
    }

};



// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n=s.length();
//         int count=0;
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         for(int i=n-1;i>=0;i--) {
//             for(int j=i;j<n;j++) {
//             if(s[i] == s[j] && (j-i <=2 || dp[i+1][j-1])) {
//                 dp[i][j]=true;
//                 count++;
//                }
//            }
//         }
//         return count;
//     }
// };
