class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=-1;
        for(int i=0;i<n;i++){
            int j=i,prev=0;
            while(j+1<n){
                int diff=nums[j+1]-nums[j];
                if(prev==0){
                    if(diff!=1 ) break;
                    prev=diff;
                    j++;
                }else{
                    if(prev==-diff){
                        prev=diff;
                        j++;
                    }else break;
                }
            }
            mx=max(mx,j-i+1);
        }
        return (mx>1)?mx:-1;
    }
};