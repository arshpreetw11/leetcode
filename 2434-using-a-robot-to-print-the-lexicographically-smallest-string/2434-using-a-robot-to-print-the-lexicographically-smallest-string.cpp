class Solution {
public:
    string robotWithString(string s) {
        stack<char> t;
        string ans="";
        int n=s.size();
        vector<char> suffix(n);
        suffix[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=(suffix[i+1]<=s[i]?suffix[i+1]:s[i]);
        }
        for(int i=0;i<n;i++){
            t.push(s[i]);
            char mn=(i+1<n)?suffix[i+1]:'{';
            while(!t.empty() && t.top()<=mn){
                ans+=t.top();
                t.pop();
            }
        }
        while(!t.empty()){
            ans+=t.top();
            t.pop();
        }
        return ans;
    }
};