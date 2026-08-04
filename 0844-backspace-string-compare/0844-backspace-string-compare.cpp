class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string resS="",resT="";
        
        for(char ch:s){
            if(ch=='#'){
                if(!resS.empty())
                resS.pop_back();
            }else{
                resS+=ch;
            }
        }
        for(char ch:t){
            if(ch=='#'){
                if(!resT.empty())
                resT.pop_back();
            }else{
                resT+=ch;
            }
        }
        return resS==resT;
    }
};