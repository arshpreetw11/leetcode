class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0),suffix(n,0);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=(nums[i]==0)?0:prefix[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=(nums[i]==0)?0:suffix[i+1]+1;
        }
        int mx=0;
        bool b=false;
        for(int i=0;i<n;i++){
            if(prefix[i]==0){
                b=true;
                int a=(i-1<0)?0:prefix[i-1];
                int b=(i+1>=n)?0:suffix[i+1];
                mx=max(mx,a+b);
            }
        }
        if(!b) return prefix[n-1]-1;
        return mx;
    }
};