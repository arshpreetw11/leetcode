class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1) return n;
        int cnt=1;
        string ans="";
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(cnt==1){
                    ans.push_back(chars[i]);
                }else{
                    ans.push_back(chars[i]);
                    ans+=to_string(cnt);
                }
                continue;
            }
            if(chars[i]!=chars[i+1]){
                if(cnt==1){
                    ans.push_back(chars[i]);
                    cnt=1;
                }else{
                    ans.push_back(chars[i]);
                    ans+=to_string(cnt);
                    cnt=1;
                }
            }
            else cnt++;
        }
        chars={};
        for(char c:ans){
            chars.push_back(c);
        }
        return ans.size();
    }
};