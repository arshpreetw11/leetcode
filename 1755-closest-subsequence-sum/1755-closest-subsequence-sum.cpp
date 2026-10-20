class Solution {
public:
    void generate(vector<int> & nums,int start,int end,long long sum,vector<long long>& sums){
        if(start==end){
            sums.push_back(sum);
            return;
        }
        generate(nums,start+1,end,sum,sums);
        generate(nums,start+1,end,sum+nums[start],sums);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int mid=n/2;

        vector<long long> left,right;
        generate(nums,0,mid,0,left);
        generate(nums,mid,n,0,right);

        sort(right.begin(),right.end());

        long long ans=LLONG_MAX;
        for(long long a:left){
            long long target=(long long)goal-a;
            auto it = lower_bound(right.begin(), right.end(), target);

            if (it != right.end()) {
                ans = min(ans, llabs(a + *it - goal));
            }

            if (it != right.begin()) {
                --it;
                ans = min(ans, llabs(a + *it - goal));
            }
            if(ans==0) return 0;
        }
        return ans;
    }
};