class Solution {
public:
using i128 = __int128_t;

i128 gcd128(i128 a, i128 b) {
    while (b != 0) {
        i128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

i128 lcm128(i128 a, i128 b) {
    return a / gcd128(a, b) * b;
}
const __int128 LIM = (__int128)1 << 120;
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            __int128_t p=1;
            __int128_t l=1;
            int g=0;
            for(int j=i;j<n;j++){
                if (p > LIM / nums[j])
                    break;
                p*=nums[j];
                g=gcd(g,nums[j]);
                l=lcm128(l,(__int128_t)nums[j]);
                if(p==(__int128_t)g*l) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};