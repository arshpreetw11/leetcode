class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n=rungs.size();
        int ans=0;
        int k=dist;
        ans += (rungs[0] - 1) / dist;
        for(int i=1;i<n;i++){
            int gap = rungs[i] - rungs[i - 1];
            ans += (gap - 1) / dist;
        }
        return ans;
    }
};