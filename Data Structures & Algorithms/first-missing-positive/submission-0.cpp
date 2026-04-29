class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: place numbers at correct index
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0 && nums[i] <= n && 
                  nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: find missing 
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
