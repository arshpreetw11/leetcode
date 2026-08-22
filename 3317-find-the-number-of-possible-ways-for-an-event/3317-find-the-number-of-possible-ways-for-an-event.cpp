class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    ll power(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1)
                ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }

    int numberOfWays(int n, int x, int y) {
        int m = min(n, x);

        vector<ll> S(m + 1);
        S[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<ll> next(m + 1);

            for (int k = 1; k <= min(i, m); k++) {
                next[k] = (S[k - 1] + k * S[k]) % MOD;
            }

            S = next;
        }

        ll ans = 0;
        ll waysStage = 1;

        for (int k = 1; k <= m; k++) {
            waysStage = waysStage * (x - k + 1) % MOD;

            ll scoreWays = power(y, k);

            ll contribution = waysStage * S[k] % MOD;
            contribution = contribution * scoreWays % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};