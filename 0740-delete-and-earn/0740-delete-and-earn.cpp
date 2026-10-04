class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int x: nums){
            freq[x]++;
        }
        int sum1=0;
        int sum2=0;
        for(int i=0;i<freq.size();i++){
            int temp=max(i*freq[i]+sum1,sum2);
            sum1=sum2;
            sum2=temp;
        }
        return sum2;
    }
};