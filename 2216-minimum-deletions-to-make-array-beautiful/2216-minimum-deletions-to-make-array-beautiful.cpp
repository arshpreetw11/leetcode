class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        int del=0,len=0;
        for(int x:nums){
            if(len%2==0){
                len++;
            }
            else{
                if(x==nums[len+del-1]){
                    del++;
                }
                else{
                    len++;
                }
            }
        }
        if(len%2==1) del++;
        return del;
    }
};