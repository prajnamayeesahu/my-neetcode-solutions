class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0, N = nums.size();

        for (int i = 0; i < N; i++) {
            if (nums[i] > nums[(i + 1) % N] && ++count > 1) {
                return false;
            }
        }

        return true;
    }
};