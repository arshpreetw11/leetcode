class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3,0);
        for(int x: nums){
            freq[x]++;
        }
        int x=0;
        for(int i=0;i<3;i++){
            while(freq[i]--){
                nums[x]=i;
                x++;
            }
        }
        
    }
};