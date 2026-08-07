class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> freq;
        for(char ch:s){
            freq[ch]++;
        }
        unordered_map<int,string> opp;
        for(auto &[c,f]:freq){
            opp[f].push_back(c);
        }
        int mx=0,sz=0;
        string ans="";
        for(auto &[n,s]:opp){
            if(mx<s.size() ||(mx==s.size() && n>sz)){
                ans=s;
                mx=s.size();
                sz=n;
            }
        }
        return ans;
    }
};