class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        vector<string> res;
        for(string s:words){
            int n=s.size();
            for(int i=0;i<n;i++){
                string sub="";
                for(int j=i;j<n;j++){
                    sub.push_back(s[j]);
                    if(st.count(sub) && sub!=s){
                        res.push_back(sub);
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};