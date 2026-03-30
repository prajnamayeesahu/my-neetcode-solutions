class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       priority_queue<pair<char, int>> maxHeap;
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});
       string res;
        while (!maxHeap.empty()) { 
         auto [cnt, ch] = maxHeap.top();
          maxHeap.pop();
           if (res.size() > 1 && res[res.size() - 1] == ch && 
           res[res.size() - 2] == ch) {
             if (maxHeap.empty()) break;
                auto [cnt2, ch2] = maxHeap.top();
                maxHeap.pop();
                res += ch2;
                if (--cnt2 > 0) maxHeap.push({cnt2, ch2});
                maxHeap.push({cnt, ch});
            } else {
                res += ch;
                if (--cnt > 0) maxHeap.push({cnt, ch});
           }
        }
        return res;
    }
};