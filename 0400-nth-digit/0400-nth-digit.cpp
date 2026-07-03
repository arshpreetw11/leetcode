class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;
        long long digit=1,count=9,start=1;
        
        while(n>digit*count){
            n-=digit*count;
            digit++;
            count*=10;
            start*=10;
        }
        long long num=start+(n-1)/digit;
        string s=to_string(num);
        return s[(n-1)%digit]-'0';
    }
};