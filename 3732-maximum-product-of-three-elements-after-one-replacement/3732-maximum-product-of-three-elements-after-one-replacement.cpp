class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        auto getMax = [&](vector<long long> arr) {
            sort(arr.begin(), arr.end());
            int m = arr.size();
            long long option1 = arr[m-1] * arr[m-2] * arr[m-3];
            long long option2 = arr[0] * arr[1] * arr[m-1];
            return max(option1, option2);
        };

        long long ans=LLONG_MIN;
        vector<long long> base(nums.begin(),nums.end());
        ans=max(ans,getMax(base));
        vector<int> idx = {0, 1, n - 2, n - 1};

        for (int i : idx) {
            vector<long long> temp(nums.begin(), nums.end());

            temp[i] = 100000;
            ans = max(ans, getMax(temp));

            temp[i] = -100000;
            ans = max(ans, getMax(temp));
        }
        return ans;
    }
};