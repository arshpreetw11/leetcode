class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        char mn=s[0],mx=s[0];
        for(char c: s){
            mn=min(mn,c);
            mx=max(mx,c);
        }
        string sorted=s;
        sort(sorted.begin(),sorted.end());
        if(s==sorted) return 0;
        if(n==2) return -1;
        if(mn==s[0] || mx==s[n-1]) return 1;
        string prefix=s.substr(0,n-1);
        string suffix=s.substr(1);
        if (prefix.find(mn) == string::npos &&
            suffix.find(mx) == string::npos) return 3;
        return 2;
    }
};