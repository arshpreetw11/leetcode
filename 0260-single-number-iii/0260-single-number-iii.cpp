class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int n : nums){
            freq[n]++;
        }
        vector<int> res;
        for(int n : nums){
            if(freq[n]==1) res.push_back(n);
        }
        return res;
    }
};