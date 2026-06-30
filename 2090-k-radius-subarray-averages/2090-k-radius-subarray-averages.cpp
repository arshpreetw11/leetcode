class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        int window=2*k +1;
        vector<int> ans(n,-1);
        if(n<window) return ans;
        vector<long long> prefix(n+1);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=k;i+k<n;i++){
            ans[i]=(prefix[i+k+1]-prefix[i-k])/window;
        }
        return ans;
    }
};