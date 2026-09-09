class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long comma=1;
        long long start=1000;
        while(start<=n){
            long long end=start*1000-1;
            long long last=min(end,n);
            ans+=(last-start+1)*comma;
            start*=1000;
            comma++;
        }
        return ans;
    }
};