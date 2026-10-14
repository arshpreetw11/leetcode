class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res(num,'0');
        if(sum>num*9) return "";
        for(int i=0;i<num && sum>0;i++){
            int d=min(9,sum);
            res[i]+=d;
            sum-=d;
        }
        return res;
    }
};