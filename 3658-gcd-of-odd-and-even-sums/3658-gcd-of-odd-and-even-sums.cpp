class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven=n*(n+1);
        int sumOdd=n*n;
        int g=gcd(sumEven,sumOdd);
        return g;
    }
};