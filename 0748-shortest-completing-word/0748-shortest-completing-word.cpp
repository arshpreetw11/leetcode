class Solution {
public:
    bool valid(string s,vector<int>& freq){
        vector<int> f(26, 0);
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                f[c - 'a']++;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(f[i] < freq[i])
                return false;
        }
        return true;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int>  freq(26,0);
        for(char c:licensePlate){
            if((c>='A' && c<='Z')||(c>='a' && c<='z')){
                c=tolower(c);
                freq[c-'a']++;
            }
        }
        string res="";
        for(string s:words){
            if(valid(s,freq)){
                if(res=="") res=s;
                else if(res.size()>s.size()) res=s;
            }
        }
        return res;
    }
};