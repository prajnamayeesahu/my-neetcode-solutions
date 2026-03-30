class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ops;
        
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                ops.pop_back();  
            } 
            else if (operations[i] == "D") {
                ops.push_back(2 * ops.back());  
            } 
            else if (operations[i] == "+") {
                int n = ops.size();
                ops.push_back(ops[n - 1] + ops[n - 2]);  
            } 
            else {
                ops.push_back(stoi(operations[i])); 
            }
        }

        int sum = 0;
        for (int i = 0; i < ops.size(); i++) {
            sum += ops[i];
        }

        return sum;
    }
};
