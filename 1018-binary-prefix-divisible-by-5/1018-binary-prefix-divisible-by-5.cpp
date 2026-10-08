class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long num=0;
        int n=nums.size();
        vector<bool> ans(n,false);
        for(int i=0;i<n;i++){
            int x=nums[i];
            num=((num*2)+x)%5;
            if(num==0) ans[i]=true;
        }
        return ans;
    }
};