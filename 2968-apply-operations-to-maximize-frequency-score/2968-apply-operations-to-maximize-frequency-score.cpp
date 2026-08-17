class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        //can perform the operations in array at most k times;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        // operation: increase or decrease by 1;
        unordered_map<int,int> freq;
        int max_freq=0;
        for(int num:nums){
            freq[num]++;
            max_freq=max(max_freq,freq[num]);
        }
        if(k==0) return max_freq;

        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }

        int len=1;
        int left=0;
        for(int right=0;right<n;right++){
            
            while(left<=right){
                int mid=(left+right)/2;
                long long leftCost=1LL*nums[mid]*(mid-left)-(prefix[mid]-prefix[left]);
                long long rightCost=(prefix[right+1]-prefix[mid+1])-1LL*nums[mid]*(right-mid);
                long long cost=leftCost+rightCost;

                if(cost<=k) break;
                left++;
            }
            len=max(len,right-left+1);
        }
        return len;
    }
};