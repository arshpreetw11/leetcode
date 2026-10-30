class Solution {
public:
    string reformat(string s) {
        string digit="",alpha="";
        for(char c:s){
            if(c<='z' && c>='a'){
                alpha+=c;
            }else{
                digit+=c;
            }
        }
        string res="";
        if(digit.size()>alpha.size() && digit.size()==alpha.size()+1){
            int i=0,j=0;
            while(i<digit.size() && j<alpha.size()){
                res+=digit[i];
                res+=alpha[j];
                i++;
                j++;
            }
            res+=digit[i];
            
        }else if(digit.size()<alpha.size() && digit.size()+1==alpha.size()){
            int i=0,j=0;
            while(i<digit.size() && j<alpha.size()){
                res+=alpha[j];
                res+=digit[i];
                i++;
                j++;
            }
            res+=alpha[j];
            
        }else if(digit.size()==alpha.size()){
            int i=0,j=0;
            while(i<digit.size() && j<alpha.size()){
                res+=digit[i];
                res+=alpha[j];
                i++;
                j++;
            }
            
        }
        return res;
    }
};