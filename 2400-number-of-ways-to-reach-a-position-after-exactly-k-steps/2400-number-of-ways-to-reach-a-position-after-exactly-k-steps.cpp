class Solution {
public:
    int mod=1e9+7;
    long long power(long long a,long long b){
        long long ans=1;

        while(b){
            if(b%2)
                ans=(ans*a)%mod;

            a=(a*a)%mod;
            b/=2;
        }

        return ans;
    }
    long long fact(int n){
        long long ans=1;
        for(long long i=2;i<=n;i++){
            ans=(ans*i)%mod;
        }
        return ans;
    }
    long long combination(int n,int r){
        if(n==r) return 1;
        long long num=fact(n);
        long long den=(fact(r)*fact(n-r))%mod;
        return (num*power(den,mod-2))%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int dist=abs(endPos-startPos);
        int Left=(k-dist)/2;
        if(dist>k||(k-dist)%2) return 0;
        //if(Left<0 || k<Left) return 0;
        return (int)combination(k,Left)%mod;
    }
};