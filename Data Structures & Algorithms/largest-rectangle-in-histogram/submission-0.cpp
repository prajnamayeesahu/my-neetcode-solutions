class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk; // {start_index, height}
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++) {
            int start = i;

            // while current height is smaller → process stack
            while(!stk.empty() && stk.top().second > heights[i]) {
                auto [index, h] = stk.top();
                stk.pop();

                int width = i - index;
                maxArea = max(maxArea, h * width);

                start = index; // extend current bar to left
            }

            stk.push({start, heights[i]});
        }

        // process remaining stack
        while(!stk.empty()) {
            auto [index, h] = stk.top();
            stk.pop();

            int width = heights.size() - index;
            maxArea = max(maxArea, h * width);
        }

        return maxArea;
    }
};