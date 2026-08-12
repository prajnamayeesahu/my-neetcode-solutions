class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);

        int maxnum = -1;

        for(int i = n - 1; i >= 0; i--) {
            res[i] = maxnum;

            maxnum = max(maxnum, arr[i]);
        }

        return res;
    }
};

