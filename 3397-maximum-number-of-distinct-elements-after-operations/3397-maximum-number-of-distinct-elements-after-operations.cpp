class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,last=INT_MIN;
        for(int num: nums){
            int x=max(num-k,last+1);
            if(x<=num+k){
                last=x;
                ans++;
            }
        }
        return ans;
    }
};