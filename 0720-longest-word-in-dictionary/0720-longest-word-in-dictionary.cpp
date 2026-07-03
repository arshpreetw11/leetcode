class Solution {
public:
    string longestWord(vector<string>& words) {
        string res="";
        unordered_set<string> st(words.begin(),words.end());
        sort(words.begin(),words.end());
        int n=words.size();
        for(string word : words){
            bool ok=true;
            string pre="";
            for(int i=0;i<word.size()-1;i++){
                pre+=word[i];
                if(!st.count(pre)){
                    ok=false;
                    break;
                }
                
            }
            if(ok){
                if(res.size()<word.size()){
                    res=word;
                }
            }
        }
        return res;
    }
};