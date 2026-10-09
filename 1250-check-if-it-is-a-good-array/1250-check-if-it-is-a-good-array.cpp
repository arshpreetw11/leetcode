class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0),suffix(n,0);
        int g=nums[0];
        for(int i=1;i<n;i++){
            g=gcd(g,nums[i]);
            if(g==1) return true;
        }
        return g==1;
    }
};