class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<string,int>> words;
        string s="";
        int n=text.size();
        for(int i=0;i<text.size();i++){
            char c=text[i];
            c=tolower(c);
            if(c==' '){
                words.push_back({s,i});
                s="";
                continue;
            }
            s+=c;
        }
        words.push_back({s,n-1});
        s="";
        sort(words.begin(),words.end(),[&](pair<string,int> a,pair<string,int> b){
            if(a.first.size()==b.first.size()){
                return a.second<b.second;
            }
            return a.first.size()<b.first.size();
        });

        string res="";
        
        for(auto &w:words){
            res+=w.first;
            res+=' ';
        }
        res[0]=toupper(res[0]);
        return res.substr(0,n);
    }
};