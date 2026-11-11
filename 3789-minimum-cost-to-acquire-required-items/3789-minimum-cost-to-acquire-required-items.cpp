class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1=min(cost1,costBoth),c2=min(cost2,costBoth);
        long long cb=min((long long)costBoth,c1+c2);
        long long shared=min(need1,need2);
        long long rem1=need1-shared;
        long long rem2=need2-shared;
        return cb*shared+c1*rem1+c2*rem2;
    }
};