class Solution {
public:
int MOD=1337;
    int modPow(int a,int b){
        a%=MOD;
        int res=1;
        while(b>0){
            if(b & 1) res=(res*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int ans=1;
        for(int d:b){
            ans=modPow(ans,10);
            ans=(ans*modPow(a,d))%MOD;
        }
        return ans;
    }
};