class Solution {
public:

    using ll = long long;
    const ll mod = 1e9 + 7;
    vector<ll> fact;

    ll power(ll a, ll b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

    ll combination(int n, int k) {
        return fact[n] * power(fact[k], mod - 2) % mod
                     * power(fact[n - k], mod - 2) % mod;
    }
    long long ways(vector<int> &nums){
        if(nums.size()<=2) return 1;
        int n=nums.size();
        int root=nums[0];
        vector<int> Left,Right;
        for(int i=1;i<n;i++){
            if(root<nums[i]) Right.push_back(nums[i]);
            else Left.push_back(nums[i]);
        }
        int l=Left.size(),r=Right.size();
        long long lw=ways(Left);
        long long rw=ways(Right);
        return combination(l+r,r)*lw%mod*rw%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        fact.assign(n+1,1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }
        return (ways(nums)-1+mod)%mod;
    }
};