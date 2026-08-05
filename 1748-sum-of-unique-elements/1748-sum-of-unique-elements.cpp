class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> freq;
        for(int n: nums){
            freq[n]++;
        }
        for(auto &f: freq){
            int v=f.second;
            if(v==1){
                ans+=f.first;
            }
        }
        return ans;
    }
};