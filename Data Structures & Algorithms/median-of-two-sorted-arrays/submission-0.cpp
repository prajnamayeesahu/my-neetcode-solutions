class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);

        int n = A.size(), m = B.size();
        int total = n + m;
        int half = (total + 1) / 2;

        int l = 0, r = n;

        while (l <= r) {
            int i = (l + r) / 2;       // cut in A
            int j = half - i;          // cut in B

            int leftA = (i == 0) ? INT_MIN : A[i - 1];
            int rightA = (i == n) ? INT_MAX : A[i];

            int leftB = (j == 0) ? INT_MIN : B[j - 1];
            int rightB = (j == m) ? INT_MAX : B[j];

            if (leftA <= rightB && leftB <= rightA) {
                // correct partition
                if (total % 2)
                    return max(leftA, leftB);
                else
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }
            else if (leftA > rightB) {
                r = i - 1; // move left
            } else {
                l = i + 1; // move right
            }
        }
        return 0;
    }
};