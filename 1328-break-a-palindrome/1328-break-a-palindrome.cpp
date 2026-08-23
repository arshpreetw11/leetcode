class Solution {
public:
    bool check(string s){
        string sub=s;
        reverse(sub.begin(),sub.end());
        return sub==s;
    }
    string breakPalindrome(string palindrome) {
        int sz=palindrome.size();
        bool changed=false;
        if(sz==1) return ""; //NOT POSSIBLE.
        
        for(int i=0;i<sz;i++){
            char ch=palindrome[i];
            if(ch!='a'){
                string temp=palindrome;
                temp[i]='a';
                if(!check(temp)){
                    palindrome[i]='a';
                    changed=true;
                    break;
                }
                
            }
        }
        if(!changed){
            palindrome[sz-1]='b';
        }
        return palindrome;
    }
};