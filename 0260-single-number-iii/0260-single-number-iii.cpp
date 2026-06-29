class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        unsigned int diff=(unsigned int)x;
        diff &= -diff;

        vector<int> res={0,0};
        for(int n : nums){
            if((n&diff)==0) res[0]^=n;
            else res[1]^=n;
        }
        return res;
    }
};