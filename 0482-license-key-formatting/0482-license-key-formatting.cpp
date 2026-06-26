class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "",ans="";
        int cnt=0;

        for(char c : s){
            if(c != '-'){
                clean += toupper(c);
            }
        }
        for(int i=clean.size()-1;i>=0;i--){
            if(cnt==k){
                ans+='-';
                cnt=0;
            }
            ans+=clean[i];
            cnt++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};