class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        int mx=*max_element(nums.begin(),nums.end());
        int mod=1e9+7;
        vector<int> freq(mx+1,0);
        for(int x: nums){
            freq[x]++;
        }

        vector<int> prefix(mx+1);
        prefix[0]=freq[0];
        for(int i=1;i<=mx;i++){
            prefix[i]=prefix[i-1]+freq[i];
        }

        for(int x=1;x<=mx;x++){
            if(freq[x]==0) continue;
            for(int l=x,q=1;l<=mx;l+=x ,q++){
                int r=min(mx,l+x-1);
                int cnt = prefix[r] - (l == 0 ? 0 : prefix[l-1]);
                sum+=1LL*freq[x]*cnt*q;
            }
        }
        return sum%mod;
    }
};