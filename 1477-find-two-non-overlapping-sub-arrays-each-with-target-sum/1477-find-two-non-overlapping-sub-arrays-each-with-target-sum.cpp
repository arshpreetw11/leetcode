class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n=nums.size();
        const int INF=1e9;

        vector<int> best(n,INF);
        int left=0;
        int sum=0;
        int minLen=INF;
        int ans=INF;

        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum==target){
                int l=right-left+1;
                if(left>0 && best[left-1]!=INF){
                    ans=min(ans,l+best[left-1]);
                }
                minLen=min(minLen,l);
            }
            best[right]=minLen;
        }
        return (ans==INF)?-1:ans;
    }
};