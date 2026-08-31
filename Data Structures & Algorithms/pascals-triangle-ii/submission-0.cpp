class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> sol;

        for(int i = 0; i <= rowIndex; i++) {

            vector<int> res(i + 1);

            res[0] = 1;
            res[i] = 1;

            for(int j = 1; j < i; j++) {
                res[j] = sol[j - 1] + sol[j];
            }

            sol = res;
        }

        return sol;
    }
};