class Solution {
public:
    bool stretchy(string s,string word){
        int i=0;
        int j=0;
        int n=s.size(),m=word.size();
        while(i<n && j<m){
            if(s[i]!=word[j]) return false;
            char c=s[i];
            int cntS = 0;
            while (i < n && s[i] == c) {
                cntS++;
                i++;
            }
            int cntW = 0;
            while (j<m && word[j] == c) {
                cntW++;
                j++;
            }
            if(cntS==cntW) continue;
            if(cntS>=3 && cntS>cntW) continue;
            return false;

        }
        return i==n && j==m;
    }
    int expressiveWords(string s, vector<string>& words) {
        int count=0;
        for(string word:words){
            if(stretchy(s,word)) count++;
        }
        return count;
    }
};