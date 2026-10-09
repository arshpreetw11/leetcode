class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();
        long long cnt=0;
        int prefix=0;
        int even=1;
        int odd=0;
        for(int x:arr){
            prefix+=x;
            if(prefix%2){
                cnt+=even;
                odd++;
            }else{
                cnt+=odd;
                even++;
            }
        }
        return cnt%mod;
    }
};