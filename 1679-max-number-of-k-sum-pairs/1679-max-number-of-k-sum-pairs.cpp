class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n:nums){
            freq[n]++;
        }
        int cnt=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i :nums){
            if(freq[i]==0) continue;
            int j=k-i;
            if(freq[j]==0) continue;
            if(i==j && freq[i]<2) continue;
            freq[i]--;
            freq[j]--;
            cnt++;
        }
        return cnt;
    }
};