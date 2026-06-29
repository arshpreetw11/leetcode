class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        unordered_map<int,int> freq;

        int n=nums.size();
        int mxLen=0;
        if(n==1) return 0;
        for(int x:nums){
            freq[x]++;
        }
        if(freq.size()==1) return 0;
        for(auto& [x,f]:freq){
            if(freq.count(x-1)) mxLen=max(mxLen,f+freq[x-1]);
        }
        return mxLen;
    }
};