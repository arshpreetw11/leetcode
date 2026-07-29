class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int moves=INT_MAX;
        int n=nums.size();
        int even=0,odd=0;
        for(int i=0;i<n;i++){
            int left=(i>0)?nums[i-1]:INT_MAX;
            int right=(i+1<n)?nums[i+1]:INT_MAX;
            int need=nums[i]-min(left,right)+1;
            if(need<0) continue;
            if(i%2==0) even+=need;
            else odd+=need;
        }
        return min(even,odd);
    }
};