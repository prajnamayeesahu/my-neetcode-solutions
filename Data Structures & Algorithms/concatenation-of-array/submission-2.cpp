class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> cnums=nums;
        for(int i=0;i<cnums.size();i++ ) {
            nums.push_back(cnums[i]);
            
        }
        return nums;
    }
};