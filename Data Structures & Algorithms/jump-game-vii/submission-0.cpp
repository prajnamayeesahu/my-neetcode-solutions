class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
         queue<int> q;
         q.push(0);
         int n=s.size();
         int farthest=0;

         while(!q.empty()) {
            int i=q.front();
            q.pop();
            int start=max(i+minJump, farthest+1);

            for(int j=start;j<min(i+ maxJump+1, n); ++j) {
                if(s[j]=='0' ) {
                    q.push(j);
                    if(j==n-1) {
                        return true;
                    }
                }
            }
            farthest=i+maxJump;
         }
         return false;
    }
};
//0->so index 0 always be 0 and if last index is 1 return false at first
//1->you cant reach there and not jump from 1 also 