class Solution {
public:
    vector<string> res;
    bool valid(string s){
        if(s.size()>1 && s[0]=='0') return false;
        if(s.length()>3) return false;
        int x=stoi(s);
        return x >= 0 && x <= 255;
    }
    void add(int idx,string &s,vector<string>& curr){
        
        if (curr.size() == 4) {
            if (idx == s.size()) {
                string ip = curr[0] + "." + curr[1] + "." +
                            curr[2] + "." + curr[3];
                res.push_back(ip);
            }
            return;
        }
        for(int len=1;len<=3;len++){
            if(len+idx>s.size()){
                break;
            }
            string part=s.substr(idx,len);
            if(valid(part)){
                curr.push_back(part);
                add(idx+len,s,curr);
                curr.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> curr;
        add(0,s,curr);
        return res;
    }
};