class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            int cnt = 0;
            int num = i;  // copy i so we can modify it
            while (num != 0) {
                cnt += (num & 1);  
                num >>= 1;         
            }
            res.push_back(cnt);
        }
        return res;
    }
};
