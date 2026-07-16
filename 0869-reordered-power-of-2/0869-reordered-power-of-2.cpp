class Solution {
public:
    vector<int> countDigits(int x) {
        vector<int> cnt(10, 0);
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        return cnt;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> target=countDigits(n);
        for(int i=0;i<31;i++){
            if(countDigits(1<<i)==target) return true;
        }
        return false;
    }
};