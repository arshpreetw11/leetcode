class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bool possible[2048]={},ans[2048]={};
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=nums[i]^nums[j];
                possible[x]=true;
            }
        }
        for(int i=0;i<2048;i++){
            if(possible[i])
            for(int k=0;k<n;k++){
                ans[i^nums[k]]=true;
            }
        }
        int res=0;
        for(int i=0;i<2048;i++){
            if(ans[i]) res++;
        }
        return res;
    }
};