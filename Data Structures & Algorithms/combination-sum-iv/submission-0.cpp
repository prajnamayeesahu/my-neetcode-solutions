class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //in cache/dp index is the sum value and corresponding save 
        unordered_map<int, long long> dp;
        dp[0]=1;
        
        for(int sum=1;sum<=target;sum++) {
            dp[sum] = 0;
            for(int num : nums) {
                if(sum>=num) {
                    dp[sum] +=dp[sum-num];
                }
            }
            if(dp[sum] > INT_MAX) {
                dp[sum]=0;
            }
        }
        return dp[target];   
    }
};