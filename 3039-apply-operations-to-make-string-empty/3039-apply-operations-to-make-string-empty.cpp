class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.size();
        int max_freq=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            max_freq=max(max_freq,++freq[s[i]]);
        }
        string ans="";
        unordered_map<char , int> currMap;
        for(int i = 0 ; i < s.size() ; i++){
            currMap[s[i]]++;
            if(max_freq == currMap[s[i]]){
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};