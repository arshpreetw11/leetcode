class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1;
        int n=s.size();
        int len=1;
        for(int i=1;i<n;i++){
            if((s[i-1]-'a')+1==(s[i]-'a')) len++;
            else{
                ans=max(ans,len);
                len=1;
            }
        }
        ans=max(ans,len);
        return ans;
    }
};