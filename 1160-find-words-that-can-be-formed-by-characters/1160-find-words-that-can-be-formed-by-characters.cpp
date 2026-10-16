class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(char ch:chars){
            freq[ch-'a']++;
        }
        int cnt=0;
        for(string word:words){
            vector<int> f=freq;
            bool b=true;
            for(char ch:word){
                f[ch-'a']--;
                if(f[ch-'a']<0){
                    b=false;
                    break;
                }
            }
            if(b) {
                cnt+=word.size();
            }
        }
        return cnt;
    }
};