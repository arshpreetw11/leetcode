class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st(dictionary.begin(),dictionary.end());
        vector<string> sen;
        string sub="";
        for(char c:sentence){
            if(c==' '){
                sen.push_back(sub);
                sub="";
            }else{
                sub+=c;
            }
        }
        sen.push_back(sub);
        for(int i=0;i<sen.size();i++){
            string word=sen[i];
            string pre="";
            for(char c:word){
                pre+=c;
                if(st.count(pre)){
                    sen[i]=pre;
                    break;
                }
            }
        }
        string res="";
        for(string x:sen){
            res+=x;
            res+=' ';
        }
        return res.substr(0,res.size()-1);
    }
};