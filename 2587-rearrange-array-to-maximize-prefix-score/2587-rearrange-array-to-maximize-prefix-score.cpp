class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0;
        int ans=0;
        for(int n:nums){
            sum+=n;
            if(sum>0) ans++;
        }
        return ans;
    }
};