class Solution {
public:
    long long minEnd(int n, int x) {
        n--; // we already have x

        long long res = x;
        int bit = 0;

        while (n > 0) {
            // if bit in x is 0, we can use it
            if ((x & (1LL << bit)) == 0) {
                if (n & 1) {
                    res |= (1LL << bit);
                }
                n >>= 1;
            }
            bit++;
        }

        return res;
    }
};