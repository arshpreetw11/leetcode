class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int ans=0;
        while(true){
            bool allZero=true;
            bool allEven=true;

            for(int i=0;i<nums.size();i++){

                if(nums[i]!=0) allZero=false;
                if(nums[i]%2) allEven=false;
            }
            if(allZero) break;
            if(allEven){
                for(int i=0;i<nums.size();i++){
                    nums[i]/=2;
                }
                ans++;
            }else{
                for(int i=0;i<nums.size();i++){
                    if(nums[i]%2){
                        nums[i]--;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};