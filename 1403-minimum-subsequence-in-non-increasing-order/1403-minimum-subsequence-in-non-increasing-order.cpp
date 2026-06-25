class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int totalSum=0;
        for(int n : nums){
            totalSum+=n;
        }
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> res;
        int s=0;
        for(int x:nums){
            s+=x;
            totalSum-=x;
            if(totalSum<s){
                res.push_back(x);
                break;
            }
            res.push_back(x);
        }
        return res;
    }
};