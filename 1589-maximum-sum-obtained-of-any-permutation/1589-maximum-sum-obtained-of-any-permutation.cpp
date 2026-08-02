class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int> diff(n+1);  //frequencies of index;
        for(auto &req:requests){
            int start=req[0];
            diff[start]++;
            int end=req[1];
            if(end+1<n){
                diff[end+1]--;
            }
        }
        vector<int> freq(n);
        freq[0]=diff[0];
        for(int i=1;i<n;i++){
            freq[i]=freq[i-1]+diff[i];
        }
        sort(nums.begin(),nums.end());
        sort(freq.begin(),freq.end());
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*nums[i]*freq[i];
        }
        int mod=1e9+7;
        return ans%mod;
    }
};