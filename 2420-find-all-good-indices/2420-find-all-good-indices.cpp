class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n,0),suffix(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                prefix[i]=0;
                continue;
            }
            if(nums[i]<=nums[i-1]){
                prefix[i]=prefix[i-1]+1;
            }else prefix[i]=0;

        }
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]<=nums[i+1]){
                suffix[i]=suffix[i+1]+1;
            }else suffix[i]=0;
        }
        vector<int> ans;
        for(int i=k;i+k<n;i++){
            int left=prefix[i-1];
            int right=suffix[i+1];
            if(left>=k-1 && right>=k-1)ans.push_back(i);
        }
        return ans;
    }
};