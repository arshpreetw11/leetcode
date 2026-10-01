class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int mod=1e9+7;
        int n=nums.size();

        long long ans=0;
        stack<int> st;
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        for(int i=0;i<=n;i++){
            long long cur=(i==n?0:nums[i]);
            while(!st.empty() && nums[st.top()]>cur){
                int j=st.top();
                st.pop();
                int left=st.empty()?-1:st.top();

                long long sum=prefix[i]-prefix[left+1];
                long long pdct=sum*nums[j];
                ans=max(ans,pdct);
            }
            st.push(i);
        }
        return ans%mod;
    }
};