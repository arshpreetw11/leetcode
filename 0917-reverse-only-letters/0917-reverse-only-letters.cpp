class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters="";
        for(char c:s){
            if((c>='a' && c<='z')||(c>='A' && c<='Z')){
                letters+=c;
            }
        }
        reverse(letters.begin(),letters.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if((c>='a' && c<='z')||(c>='A' && c<='Z')){
                s[i]=letters[j];
                j++;
            }
        }
        return s;
    }
};