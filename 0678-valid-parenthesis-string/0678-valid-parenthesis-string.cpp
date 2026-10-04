class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int min=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++;
                mx++;
            }else if(s[i]==')'){
                min--;
                mx--;
            }
            else{
                min--;
                mx++;
            }
            if(mx<0) return false;
            if(min<0) min=0;

        }
        if(min==0) return true;
        return false;
    }
};