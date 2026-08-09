class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long total=0;
        unordered_map<int,int> freq;

        for(int x: nums){
            total+=x;
            freq[x]++;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {

            int outlier = nums[i];

            long long remaining = total - outlier;

            if (remaining % 2 != 0)
                continue;

            long long sumElement = remaining / 2;

            if (freq.count(sumElement)) {
                if (sumElement == outlier) {
                    if (freq[outlier] >= 2)
                        return outlier;
                }
                else {
                    return outlier;
                }
            }
        }
        return -1;
        
    }
};