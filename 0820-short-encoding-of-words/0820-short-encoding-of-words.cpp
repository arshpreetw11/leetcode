class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        for(string w:words){
            for(int i=1;i<w.size();i++){
                st.erase(w.substr(i));
            }
        }
        int ans=0;
        for(auto &s:st){
            ans+=s.size()+1;
        }
        return ans;
    }
};