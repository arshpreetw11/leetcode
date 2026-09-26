class Solution {
public:
string res="";
unordered_map<string, string> mp;
    void rep(int &i,string s,vector<vector<string>>& knowledge){
        string r="";
        while(s[i]!=')'){
            r+=s[i];
            i++;
        }
        bool found=false;
        if(mp.count(r)){
            res+=mp[r];
        }else{
            res+='?';
        }
        i++;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        

        for (auto &p : knowledge) {
            mp[p[0]] = p[1];
        }
        int i=0;
        int n=s.size();
        while(i<n){
            if(s[i]=='('){
                i++;
                rep(i,s,knowledge);
            }else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};