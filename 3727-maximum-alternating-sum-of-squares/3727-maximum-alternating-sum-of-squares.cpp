class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        int add=(n%2)?n/2+1:n/2;
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int i=0;
        while(add--){
            sum+=nums[i]*nums[i];
            i++;
        }
        while(i<n){
            sum-=nums[i]*nums[i];
            i++;
        }
        return sum;
    }
};