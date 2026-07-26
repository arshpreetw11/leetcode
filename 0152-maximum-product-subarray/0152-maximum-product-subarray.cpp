class Solution {
public:
int pdct=INT_MIN;
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int m=nums[i];
            if(m>pdct) pdct=m;
            for(int j=i+1;j<n;j++){
                 m=m*nums[j];
                if(m>pdct) pdct=m;
            }
            
        }
        return pdct;
    }
};