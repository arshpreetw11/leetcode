class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        deque<int> start;
        long long ans=0,water=0;
        int n=nums.size(),r=n-1;
        for(int l=n-1;l>=0;l--){
            int x=nums[l];
            while(!start.empty() && nums[start.front()]<=x){
                int s=start.front();
                start.pop_front();
                int end=start.empty()?r+1:start.front();
                water+=1LL*(x-nums[s])*(end-s);
            }
            start.push_front(l);
            while(water>k){
                water-=nums[start.back()]-nums[r];
                if(start.back()==r){
                    start.pop_back();
                }
                --r;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};