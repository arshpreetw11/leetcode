class Solution {
public:
    bool check(string s,string sub){
        unordered_map<char,int> freqS,freqSub;
        for(char c:sub){
            freqSub[c]++;
        }
        for(char c:s){
            freqS[c]++;
        }
        for(auto &[c,n]:freqSub){
            if(n>freqS[c]) return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> freq2(26,0);
        for(string &s: words2){
            vector<int> freq(26,0);
            for(char c:s){
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                freq2[i]=max(freq2[i],freq[i]);
            }
        }

        for(string s:words1){
            vector<int> freq(26,0);
            for(char c:s){
                freq[c-'a']++;
            }
            bool valid=true;
            for(int i=0;i<26;i++){
                if(freq[i]<freq2[i]){
                    valid=false;
                    break;
                }
            }
            if(valid) res.push_back(s);
        }
        return res;
    }
};