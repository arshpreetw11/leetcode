class Solution {
public:
bool isLower(char ch){
    return ch>='a' && ch<='z';
}
bool isUpper(char ch){
    return ch>='A' && ch<='Z';
}
bool isDigit(char ch){
    return ch>='0' && ch<='9';
}
    int strongPasswordChecker(string password) {
        int n=password.size();
        bool lower=false,upper=false,digit=false;
        for(char ch:password){
            if(isLower(ch)) lower=true;
            if(isUpper(ch)) upper=true;
            if(isDigit(ch)) digit=true;
        }
        int missing=3-(lower+upper+digit);
        if(n<6){
            return max(6-n,missing);
        }
        int replace=0;
        int cnt[3]={};
        for(int i=0;i<n;){
            int j=i;
            while(j<n && password[i]==password[j]) j++;
            int len=j-i;
            if(len>=3){
                replace+=len/3;
                cnt[len%3]++;
            }
            i=j;
        }
        if(n <= 20) {
            return max(missing, replace);
        }
        int del=n-20;
        int remdel=del;

        int use=min(remdel,cnt[0]);
        replace-=use;
        remdel-=use;

        use=min(remdel/2,cnt[1]);
        replace-=use;
        remdel-=use*2;

        use=remdel/3;
        replace-=use;
        replace=max(0,replace);
        return del+max(missing,replace);
    }
};