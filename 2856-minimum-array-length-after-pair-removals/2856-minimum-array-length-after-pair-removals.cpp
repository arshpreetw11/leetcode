class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int,int> freq;
        int mx=0;
        for(int n:nums){
            freq[n]++;
            mx=max(mx,freq[n]);
        }
        int n=nums.size();
        if(2*mx>n){
            return 2*mx-n;
        }
        return n%2;
    }
};