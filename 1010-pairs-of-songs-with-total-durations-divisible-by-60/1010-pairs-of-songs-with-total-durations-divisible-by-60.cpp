class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        vector<int> val(60);
        int ans=0;
        for(int t:time){
            int rem=t%60;
            int find=(60-rem)%60;

            ans+=val[find];
            val[rem]++;
        }
        return ans;
    }
};