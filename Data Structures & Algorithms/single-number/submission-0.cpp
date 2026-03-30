class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> h;
        for(int i=0;i<nums.size();i++) {
            if(h.count(nums[i])) {
               h.erase(nums[i]);
            } else {
                h.insert(nums[i]);
            }
        }
        return *h.begin();
    }
};
