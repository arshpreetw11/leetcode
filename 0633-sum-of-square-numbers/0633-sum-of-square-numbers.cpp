class Solution {
public:
    bool perfect(int c,int x){
        double y=c-x*x;
        int s=sqrt(y);
        return s*s==y;
    }
    bool judgeSquareSum(int c) {
        if(c<=1) return true;
        for(long long i=0;i*i<c;i++){
            if(perfect(c,i)) return true;
        }
        return false;
    }
};