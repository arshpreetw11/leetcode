class Solution {
public:
    bool backtrack(int idx,vector<int>& nums,vector<int>&buckets,int target){
        if(idx==nums.size()) return true;
        int curr=nums[idx];
        for(int i=0;i<buckets.size();i++){
            if(curr+buckets[i]>target) continue;

            buckets[i]+=curr;
            if(backtrack(idx+1,nums,buckets,target)) return true;
            buckets[i]-=curr;
            if(buckets[i]==0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //sum of each subarray >= max_element;
        int total=0;
        for(int n: nums){
            total+=n;
        }
        int mx=*max_element(nums.begin(),nums.end());
        if(mx==total && k==1) return true;
        if(total%k!=0) return false;
        int target=total/k;
        sort(nums.rbegin(),nums.rend());
        if(target<nums[0]) return false;
        vector<int> buckets(k,0);
        return backtrack(0,nums,buckets,target);
    }
};