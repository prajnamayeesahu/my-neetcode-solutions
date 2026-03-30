class Solution {
public:
    string convertToTitle(int columnNumber) {
    string result = "";
        while (columnNumber > 0) {
            columnNumber--; // adjust for 1-based system
            char c = 'A' + (columnNumber % 26);
            result = c + result; // build from right to left
            columnNumber /= 26;
        }
        return result;
    }
};