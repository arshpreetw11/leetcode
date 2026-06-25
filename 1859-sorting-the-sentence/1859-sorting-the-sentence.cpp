class Solution {
public:
    string sortSentence(string s) {
        int size=0;
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - 1 || s[i + 1] == ' ') {
                size = max(size, s[i] - '0');
            }
        }
        vector<string> sub(size,"");
        string x="";
         for (int i = 0; i < s.size(); i++) {
            if(s[i]==' ') continue;
            if (i == s.size() - 1 || s[i + 1] == ' ') {
                sub[s[i] - '0' - 1] = x;
                x = "";
            }
            else {
                x += s[i];
            }
        }
        string res="";
        for(int i=0;i<size;i++){
            if (i) res += " ";
            res += sub[i];
        }
        return res;
    }
};