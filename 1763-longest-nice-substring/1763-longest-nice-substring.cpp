class Solution {
public:
    bool isValid(string s){
        unordered_set<char> st(s.begin(),s.end());
        for (char ch : s) {
            if (islower(ch)) {
                if (!st.count(toupper(ch)))
                    return false;
            } else {
                if (!st.count(tolower(ch)))
                    return false;
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                if(isValid(temp)){
                    if(res.size()<temp.size()){
                        res=temp;
                    }
                }
            }
        }
        return res;
    }
};