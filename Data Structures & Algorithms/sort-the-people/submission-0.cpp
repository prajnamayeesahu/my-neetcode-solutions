class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> map;
        for(int i=0;i<heights.size();i++) {
            map[heights[i]]=names[i];
        }

        sort(heights.begin(), heights.end());
        vector<string> res;
        for(int i=heights.size()-1;i>=0;i--) {
            res.push_back(map[heights[i]]);
        }

        return res;
    }
};