class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(canSplit(nums, k, mid)) {
                high = mid;   // try smaller answer
            } else {
                low = mid + 1; // need bigger limit
            }
        }

        return low;
    }

    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int currSum = 0;
        int parts = 1;

        for(int num : nums) {
            if(currSum + num > maxSum) {
                parts++;       // new subarray
                currSum = num;
            } else {
                currSum += num;
            }
        }

        return parts <= k;
    }
};