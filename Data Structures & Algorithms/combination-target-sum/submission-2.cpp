class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtrack(vector<int>& nums, int target, int index) {

        if (target == 0) {
            res.push_back(curr);
            return;
        }

        if (target < 0 || index == nums.size())
            return;

        // Choice 1: Take current number
        curr.push_back(nums[index]);
        backtrack(nums, target - nums[index], index); // same index
        curr.pop_back(); // backtrack

        // Choice 2: Skip current number
        backtrack(nums, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return res;
    }
};