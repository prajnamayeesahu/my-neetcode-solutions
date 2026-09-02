class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> oddSet;

        for (int num : nums) {
            if (oddSet.count(num)) {
                oddSet.erase(num);
            } else {
                oddSet.insert(num);
            }
        }

        return oddSet.empty();
    }
};