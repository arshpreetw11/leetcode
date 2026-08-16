class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int pairs=0;
        for(int i=0;i<n;i++){
            int a=nums[i];
            for(int j=i+1;j<n;j++){
                int b=nums[j];
                if(a==b) continue;
                for(int k=j+1;k<n;k++){
                    int c=nums[k];
                    if(b!=c && a!=c){
                        pairs++;
                    }
                }
            }
        }
        return pairs;
    }
};