class Solution {
public:
void solve(int idx,string &digits,string &curr,vector<string> &res,unordered_map<char, string> &t){
    if(digits.size()==curr.size()){
        res.push_back(curr);
        return;
    }
    char x=digits[idx];
    for(auto ch:t[x]){
        curr.push_back(ch);
        solve(idx+1,digits,curr,res,t);
        curr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> t;
        t['2']="abc";t['3']="def";t['4']="ghi";t['5']="jkl";t['6']="mno";
        t['7']="pqrs";t['8']="tuv";t['9']="wxyz";
        vector<string> res;
        string curr="";
        solve(0,digits,curr,res,t);
        return res;
    }
};