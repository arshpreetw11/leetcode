class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int m=nums[0];
        vector<long long> prefixGCD(n);
        for(int i=0;i<n;i++){
            m=max(nums[i],(int)m);
            prefixGCD[i]=gcd(nums[i],m);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int i=0,j=n-1;
        long long sum=0;
        while(i<j){
            long long g=gcd(prefixGCD[i],prefixGCD[j]);
            sum+=g;
            i++;
            j--;
        }
        return sum;
    }
};