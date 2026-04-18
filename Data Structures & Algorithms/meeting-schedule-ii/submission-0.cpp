/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;

        // Step 1: sort by start time
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        // Min heap (store end times)
        priority_queue<int, vector<int>, greater<int>> pq;

        // First meeting
        pq.push(intervals[0].end);

        for(int i = 1; i < intervals.size(); i++) {
            // If current meeting starts after earliest end → reuse room
            if(intervals[i].start >= pq.top()) {
                pq.pop();
            }

            // Allocate room
            pq.push(intervals[i].end);
        }

        return pq.size();
    }
};