class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> res;
        
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]) continue;
            else res.push_back(nums[i]);
        }
        return res;
    }
};