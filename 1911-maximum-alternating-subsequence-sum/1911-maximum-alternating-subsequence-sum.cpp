class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even=0;
        long long odd=-4e18;

        for(long long x: nums){
            long long newOdd=odd;
            long long newEven=even;
            even=max(newEven,newOdd-x);
            odd=max(newOdd,newEven+x);
        }   
        return odd;
    }
};