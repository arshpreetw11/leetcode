class Solution {
public:

    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        unordered_map<int,int> freq;
        unordered_map<int,int> need;
        for(int x: nums){
            freq[x]++;
            need[x]=0;
        }
        for(int x: nums){
            if(freq[x]<=0) continue;
            if(need[x]>0){
                need[x]--;
                need[x+1]++;
                freq[x]--;
            }else if(freq[x+2]>0 && freq[x+1]>0){
                freq[x]--;
                freq[x+1]--;
                freq[x+2]--;
                need[x+3]++;
            }else{
                return false;
            }
        }
        return true;
    }
};