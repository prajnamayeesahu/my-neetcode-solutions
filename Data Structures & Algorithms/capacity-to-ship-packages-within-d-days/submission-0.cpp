class Solution {
public:
    bool canShip(vector<int>& weights, int D, int capacity) {
        int days = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > capacity) {
                days++;
                load = 0;
            }
            load += w;
        }

        return days <= D;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = (left + right) / 2;

            if (canShip(weights, D, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};


// Capacity = container size
// Packages = water
// Fill until overflow
// Overflow → new day

// Whenever you see:

// “Minimum X such that condition works”

// Think:

// Binary Search on Answer