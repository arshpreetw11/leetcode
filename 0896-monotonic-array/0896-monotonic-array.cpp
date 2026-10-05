class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=false;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                inc=true;
                break;
            }
            else if(nums[i-1]>nums[i]){
                break;
            }
        }
        if(inc){
            for(int i=1;i<nums.size();i++){
                if(nums[i-1]>nums[i]) return false;
            }
        }else{
            for(int i=1;i<nums.size();i++){
                if(nums[i-1]<nums[i]) return false;
            }
        }
        return true;
    }
};