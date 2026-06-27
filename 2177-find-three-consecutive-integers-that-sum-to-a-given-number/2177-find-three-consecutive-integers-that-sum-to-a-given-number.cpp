class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long x=0;
        if(num%3!=0) return {};
        x=num/3;
        vector<long long > res(3);
        res[0]=x-1;
        res[1]=x;
        res[2]=x+1;
        return res;
    }
};