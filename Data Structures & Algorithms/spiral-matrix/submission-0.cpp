class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while(top <= bottom && left <= right) {

            // 1. top row
            for(int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // 2. right column
            for(int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // 3. bottom row
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // 4. left column
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};