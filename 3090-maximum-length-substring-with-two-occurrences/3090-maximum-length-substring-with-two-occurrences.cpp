class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res=0;
        int freq[26]={0};
        for(int l=0,r=0;r<s.length();r++){
            freq[(s[r]&31)-1]++;
            while(freq[(s[r]&31)-1]>2){
                freq[(s[l++]&31)-1]--;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};