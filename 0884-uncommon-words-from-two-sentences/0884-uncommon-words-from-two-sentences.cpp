class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> freq;
        string temp="";
        for(char c:s1){
            if(c==' '){
                freq[temp]++;
                temp="";
                continue;
            }
            temp+=c;
        }
        freq[temp]++;
        temp="";
        for(char c:s2){
            if(c==' '){
                freq[temp]++;
                temp="";
                continue;
            }
            temp+=c;
        }
        freq[temp]++;
        vector<string> res;
        for(auto &[s,f]:freq){
            if(f==1) res.push_back(s);
        }
        return res;
    }
};