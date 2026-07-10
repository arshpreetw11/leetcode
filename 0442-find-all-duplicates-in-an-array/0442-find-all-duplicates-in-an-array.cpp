class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> freq;
        sort(nums.begin(),nums.end());
        for(int n: nums){
            freq[n]++;
            if(freq[n]==2){
                res.push_back(n);
            }
        }
        return res;
    }
};