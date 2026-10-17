class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        int mx=0;
        vector<int> prefix(n);
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]==0) prefix[i]=-1;
                else prefix[i]=1;

                continue;
            }
            if(nums[i]==0)
                prefix[i]=prefix[i-1]-1;
            else 
                prefix[i]=prefix[i-1]+1;
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(mp.count(prefix[i])){
                int firstidx=mp[prefix[i]];
                mx=max(mx,i-firstidx);
            }else
            mp[prefix[i]]=i;
        }
        return mx;
    }
};