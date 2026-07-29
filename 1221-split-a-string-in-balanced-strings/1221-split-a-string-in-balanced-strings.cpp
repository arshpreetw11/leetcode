class Solution {
public:
    int balancedStringSplit(string s) {
        int balance=0;
        int ans=0;
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]!='L'){
                balance--;
            }
            if(s[i]=='L')
                balance++;
            if(balance==0) ans++;
            i++;
        }
        return ans;
    }
};