class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        long long ans=0,cur=1;
        for(int x: nums){
            if(x<cur) continue;
            long long cnt=min((long long)k,(long long)x-cur);
            ans+=(cur+cnt+cur-1)*(cnt)/2;
            k-=cnt;
            if(k==0) return ans;
            cur=(long long)x+1;
        }
        if(k>0){
            ans+=(cur+cur+k-1)*(k)/2;
        }
        return ans;
    }
};