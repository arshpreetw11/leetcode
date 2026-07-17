class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<long long> freq(mx+1,0);
        for(int x:nums){
            freq[x]++;
        }
        vector<long long> cnt(mx+1,0);
        for(int g=1;g<=mx;g++){
            for(int mult=g;mult<=mx;mult+=g){
                cnt[g]+=freq[mult];
            }
        }
        //count pairs;
        vector<long long> exact(mx+1,0);
        for(int g=mx;g>=1;g--){
            exact[g]=cnt[g]*(cnt[g]-1)/2;
            for(int mul=2*g;mul<=mx;mul+=g){
                exact[g]-=exact[mul];
            }
        }
        vector<long long> pref(mx+1,0);
        pref[0]=exact[0];
        for(int i=1;i<=mx;i++){
            pref[i]=exact[i]+pref[i-1];
        }
        vector<int> ans;
        for(long long q: queries){
            ans.push_back(upper_bound(pref.begin(), pref.end(), q) - pref.begin());
        }
        return ans;
    }
};