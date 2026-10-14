class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long num=0;
        int n=s.size();
        int len=0;
        int bitPos=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                len++;
                bitPos++;
            }else{
                if(bitPos<63 && num+(1LL<<bitPos)<=k){
                    num+=(1LL<<bitPos);
                    len++;
                    bitPos++;
                }
            }
        }
        return len;
    }
};