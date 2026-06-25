class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        for(int i=0;i<nums.size();i++){
            int small=0;
            for(int j=0;j<temp.size();j++){
                if(temp[j]==nums[i]) break;
                small++;
            }
            res.push_back(small);
        }
        return res;
    }
};