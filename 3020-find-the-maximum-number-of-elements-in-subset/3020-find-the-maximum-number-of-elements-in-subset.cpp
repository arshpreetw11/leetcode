class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long ,int> freq;
        for(int n:nums){
            freq[n]++;
        }
        int n=nums.size();
        int ans=1;
        if(freq.count(1)){
            if(freq[1]%2==0){
                ans=max(ans,freq[1]-1);
            }
            else
                ans=max(ans,freq[1]);
        }

        for(auto &[start,cnt]:freq){
            if(start==1) continue;
            long long x=start;
            int len=0;
            while (true) {
            auto it = freq.find(x);
            if (it == freq.end() || it->second < 2)
                break;
            len += 2;
            if (x > 1000000000LL / x)
                break;
            x *= x;
        }

        auto it = freq.find(x);
        if (it != freq.end() && it->second == 1)
            len++;
        else if (len > 0)
            len--;

        ans=max(ans,len);
        }
        return ans;
    }
};