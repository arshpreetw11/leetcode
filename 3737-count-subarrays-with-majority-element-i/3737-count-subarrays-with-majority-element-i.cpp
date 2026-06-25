class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        vector<int> temp(n+1,0);
        for(int i=0;i<n;i++){
            temp[i+1]=temp[i]+(nums[i]==target); 
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len=j-i+1;
                int ct=temp[j+1]-temp[i];
                if(ct*2>len) count++;
            }
        }
        // unordered_map<int,int> freq;
        // for(int x:nums){
        //     freq[x]++;
        // }
        // if(freq[target]==1) return 1;
        // for(int i=0;i<n;i++){
        //     unordered_map<int,int> subfreq;
        //     vector<int> res;
        //     for(int j=i;j<n;j++){
        //         res.push_back(nums[j]);
        //         subfreq[nums[j]]++;
        //         int len=res.size();
        //         int val=subfreq[target];
        //         if(2*val>len) count++;
        //     }
        // }
        return count;
    }
};