class Solution {
public:
    string binary(int n){
        string s="";
        while(n!=0){
            s+=(n%2)?'1':'0';
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    bool queryString(string s, int n) {
        if(n>1000) return false;
        for(int i=n;i>(n/2);--i){
            string b = binary(i);
            if(s.find(b)==string::npos) return false;
        }
        return true;
    }
};