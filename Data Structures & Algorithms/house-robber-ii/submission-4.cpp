class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // edge case
        if (n == 1) return nums[0];

        // case 1: exclude last
        int case1 = helper(nums, 0, n - 2);

        // case 2: exclude first
        int case2 = helper(nums, 1, n - 1);

        return max(case1, case2);
    }

    int helper(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;

        for (int i = start; i <= end; i++) {
            int newRob = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = newRob;
        }

        return rob2;
    }
};